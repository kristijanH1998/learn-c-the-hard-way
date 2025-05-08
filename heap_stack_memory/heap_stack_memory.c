#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Structs
struct Address {
    int id;
    int set;
    char *name;
    char *email;
    int *year_created;
};

struct Database {
    int max_rows;
    int max_data;
    struct Address **rows;
};

struct Connection {
    FILE *file;
    struct Database *db;
};

// Function declarations
void Database_close(struct Connection *conn);

void die(const char *message, struct Connection *conn) {
    if (errno) {
        perror(message);
    } else {
        fprintf(stderr, "ERROR: %s\n", message);
    }
    Database_close(conn);
    exit(1);
}

void Address_print(struct Address *addr) {
    printf("%d %s %s %d\n", addr->id, addr->name, addr->email, *(addr->year_created));
}

void Database_load(struct Connection *conn) {
    struct Database *db = conn->db;
    int rc = fread(&db->max_rows, sizeof(int), 1, conn->file);
    rc += fread(&db->max_data, sizeof(int), 1, conn->file);
    if (rc != 2)
        die("Failed to read database metadata.", conn);

    db->rows = malloc(sizeof(struct Address*) * db->max_rows);
    if (!db->rows)
        die("Memory allocation failed for rows.", conn);

    for (int i = 0; i < db->max_rows; i++) {
        struct Address *addr = malloc(sizeof(struct Address));
        addr->name = malloc(db->max_data);
        addr->email = malloc(db->max_data);
        addr->year_created = malloc(sizeof(int));
        if (!addr || !addr->name || !addr->email || !addr->year_created)
            die("Memory allocation failed for address.", conn);

        fread(&addr->id, sizeof(int), 1, conn->file);
        fread(&addr->set, sizeof(int), 1, conn->file);
        fread(addr->name, sizeof(char), db->max_data, conn->file);
        fread(addr->email, sizeof(char), db->max_data, conn->file);
        fread(addr->year_created, sizeof(int), 1, conn->file);

        db->rows[i] = addr;
    }
}

void Database_write(struct Connection *conn) {
    rewind(conn->file);
    struct Database *db = conn->db;

    int rc = fwrite(&db->max_rows, sizeof(int), 1, conn->file);
    rc += fwrite(&db->max_data, sizeof(int), 1, conn->file);

    for (int i = 0; i < db->max_rows; i++) {
        struct Address *addr = db->rows[i];
        rc += fwrite(&addr->id, sizeof(int), 1, conn->file);
        rc += fwrite(&addr->set, sizeof(int), 1, conn->file);
        rc += fwrite(addr->name, sizeof(char), db->max_data, conn->file);
        rc += fwrite(addr->email, sizeof(char), db->max_data, conn->file);
        rc += fwrite(addr->year_created, sizeof(int), 1, conn->file);
    }

    if (rc < 2 + db->max_rows * (3 + 2 * db->max_data / sizeof(int)))
        die("Failed to write database.", conn);

    if (fflush(conn->file) == -1)
        die("Cannot flush database.", conn);
}

void Database_create(struct Connection *conn, int max_rows, int max_data) {
    conn->db->max_rows = max_rows;
    conn->db->max_data = max_data;
    conn->db->rows = malloc(sizeof(struct Address*) * max_rows);
    if (!conn->db->rows)
        die("Memory allocation failed for rows.", conn);

    for (int i = 0; i < max_rows; i++) {
        struct Address *addr = malloc(sizeof(struct Address));
        addr->name = malloc(max_data);
        addr->email = malloc(max_data);
        addr->year_created = malloc(sizeof(int));
        if (!addr || !addr->name || !addr->email || !addr->year_created)
            die("Memory allocation failed for address.", conn);
        addr->id = i;
        addr->set = 0;
        conn->db->rows[i] = addr;
    }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email, int year_created) {
    struct Address *addr = conn->db->rows[id];
    if (addr->set)
        die("Already set, delete it first.", conn);

    addr->set = 1;
    strncpy(addr->name, name, conn->db->max_data);
    addr->name[conn->db->max_data - 1] = '\0';
    strncpy(addr->email, email, conn->db->max_data);
    addr->email[conn->db->max_data - 1] = '\0';
    int *year = malloc(sizeof(int));
    *year = year_created;
    addr->year_created = year;
}

void Database_get(struct Connection *conn, int id) {
    struct Address *addr = conn->db->rows[id];
    if (addr->set)
        Address_print(addr);
    else
        die("ID is not set.", conn);
}

void Database_delete(struct Connection *conn, int id) {
    struct Address *addr = conn->db->rows[id];
    addr->set = 0;
}

void Database_list(struct Connection *conn) {
    struct Database *db = conn->db;
    for (int i = 0; i < db->max_rows; i++) {
        struct Address *cur = db->rows[i];
        if (cur->set)
            Address_print(cur);
    }
}

void Database_close(struct Connection *conn) {
    if (conn) {
        if (conn->file)
            fclose(conn->file);

        if (conn->db) {
            for (int i = 0; i < conn->db->max_rows; i++) {
                struct Address *addr = conn->db->rows[i];
                if (addr) {
                    free(addr->name);
                    free(addr->email);
                    free(addr->year_created);
                    free(addr);
                }
            }
            free(conn->db->rows);
            free(conn->db);
        }

        free(conn);
    }
}

struct Connection *Database_open(const char *filename, char mode) {
    struct Connection *conn = malloc(sizeof(struct Connection));
    if (!conn)
        die("Memory error", NULL);

    conn->db = malloc(sizeof(struct Database));
    if (!conn->db)
        die("Memory error", conn);

    if (mode == 'c') {
        conn->file = fopen(filename, "w+");
    } else {
        conn->file = fopen(filename, "r+");
        if (conn->file) {
            Database_load(conn);
        }
    }

    if (!conn->file)
        die("Failed to open the file.", conn);

    return conn;
}

struct Address *Address_find(struct Connection *conn, char *name, char *email, int year_created, char search_by) {
    int i = 0;
    struct Address *addr = NULL;
    if(search_by == 'n') {
        for(i = 0; i < conn->db->max_data; i++) {
            if(strcmp(conn->db->rows[i]->name, name) == 0) {
                addr = conn->db->rows[i];
                Address_print(conn->db->rows[i]);
                break;
            }
        }
    } else if(search_by == 'e'){
        for(i = 0; i < conn->db->max_data; i++) {
            if(strcmp(conn->db->rows[i]->email, email) == 0) {
                addr = conn->db->rows[i];
                Address_print(conn->db->rows[i]);
                break;
            }
        }
    } else {
        for(i = 0; i < conn->db->max_data; i++) {
            if(*(conn->db->rows[i]->year_created) == year_created) {
                addr = conn->db->rows[i];
                Address_print(conn->db->rows[i]);
                break;
            }
        }
    }
    if(!addr) {
        puts("No results found.");
        return NULL;
    } 
    return addr;
}

// Main driver
int main(int argc, char *argv[]) {
    if (argc < 3)
        die("USAGE: ex17 <dbfile> <action> [action params]", NULL);

    char *filename = argv[1];
    char action = argv[2][0];
    struct Connection *conn = Database_open(filename, action);
    int id = 0;

    if (action != 'c') {
        if (argc > 3)
            id = atoi(argv[3]);
        if (id >= conn->db->max_rows)
            die("There's not that many records.", conn);
    }

    switch (action) {
        case 'c':
            if (argc != 5)
                die("Need MAX_ROWS and MAX_DATA to create a database.", conn);
            Database_create(conn, atoi(argv[3]), atoi(argv[4]));
            Database_write(conn);
            break;
        case 'g':
            if (argc != 4)
                die("Need an id to get.", conn);
            Database_get(conn, id);
            break;
        case 's':
            if (argc != 7)
                die("Need id, name, email, year_created to set.", conn);
            Database_set(conn, id, argv[4], argv[5], (atoi(argv[6])));
            Database_write(conn);
            break;
        case 'd':
            if (argc != 4)
                die("Need id to delete.", conn);
            Database_delete(conn, id);
            Database_write(conn);
            break;
        case 'l':
            Database_list(conn);
            break;
        case 'f':
            if(argv[3][0] == 'n') {
                Address_find(conn, argv[4], "", 0, 'n');
            } else if(argv[3][0] == 'e'){
                Address_find(conn, "", argv[4], 0, 'e');
            } else if(argv[3][0] == 'y') {
                Address_find(conn, "", "", atoi(argv[4]), 'y');
            } else {
                die("After action 'f', enter 'n' for name or 'e' for email, followed by search string.", conn);
            }
            break;
        default:
            die("Invalid action: c=create, g=get, s=set, d=del, l=list, f=find", conn);
    }

    Database_close(conn);
    return 0;
}


