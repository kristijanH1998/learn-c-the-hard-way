#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

struct Person {
    int age;
    char name[50];
    char residence[50];
};

int main(int argc, char *argv[]) {
    const char *filename = "textfile.txt";
    // FILE *fp = fopen(filename, "r");
    // if(fp == NULL) {
    //     fp = fopen(filename, "w");
    //     if(fp == NULL) {
    //         perror("Error creating file.");
    //         return 1;
    //     }
    //     fprintf(fp, "This is a typical Hello World sentence.\n");
    //     fclose(fp);
    //     fp = fopen(filename, "r");
    //     if(fp == NULL) {
    //         perror("Error opening file.");
    //         return 1;
    //     }
    // }
    // char buf[100];
    // while(fscanf(fp, "%s", buf) == 1) {
    //     // if(strcmp(buf, "\n") == 0) {
    //     //     printf("\n");
    //     // }
    //     printf("%s ", buf);
    // }
    // printf("\n");
    // rewind(fp);
    // while(fgets(buf, 100, fp)) {
    //     // if(strcmp(buf, "\n") == 0) {
    //     //     printf("\n");
    //     // }
    //     printf("%s ", buf);
    // }
    // // printf("\n");
    // freopen(filename, "w", fp);
    // fprintf(fp, "1.23 4.56 7.89\n");
    // float fl1, fl2, fl3;
    // if(fscanf(fp, "%f %f %f", &fl1, &fl2, &fl3) == 3) {
    //     printf("%.2f %.2f %.2f\n", fl1, fl2, fl3);
    // }
    // fclose(fp);
    // // remove(filename);
    // int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    // if(fd == -1) {
    //     perror("open error");
    //     exit(EXIT_FAILURE);
    // }
    // FILE *fp2;
    // fp2 = fdopen(fd, "w");
    // if(fp2 == NULL) {
    //     perror("fdopen error");
    //     close(fd);
    //     exit(EXIT_FAILURE);
    // }
    // fprintf(fp2, "Hello world!\n");
    // while(fgets(buf, 100, fp2)) {
    //     printf("%s ", buf);
    // }
    // if(fcloseall() != 0){
    //     perror("fcloseall error");
    //     exit(EXIT_FAILURE);
    // }
    
    //---------------------------------------------------------------------------

    // FILE *fp3 = fopen(filename, "w");
    // if(fp3 == NULL) {
    //     fp3 = fopen(filename, "w");
    //     if(fp3 == NULL) {
    //         perror("error creating file");
    //         return 1;
    //     }
    // }
    // fprintf(fp3, "New hello world sentence.");
    // fseek(fp3, 0L, SEEK_END);
    // fprintf(fp3, " And more text...");
    // printf("file position indicator: %ld\n", ftell(fp3));
    // fseek(fp3, 0L, SEEK_SET);
    // fprintf(fp3, "Sentence edited here.");
    // fpos_t position;
    // if(fgetpos(fp3, &position) != 0) {
    //     perror("Error getting file position.\n");
    //     return 1;
    // }
    // fprintf(fp3, "...change...");
    // rewind(fp3);
    // fprintf(fp3, "SECONDCHANGE");
    // printf("file position indicator: %ld\n", ftell(fp3));
    // fpos_t pos_temp;
    // fgetpos(fp3, &pos_temp);
    // rewind(fp3);
    // fsetpos(fp3, &pos_temp);
    // printf("file position indicator: %ld\n", ftell(fp3));
    // fseek(fp3, 0L, SEEK_SET);
    // printf("file position indicator: %ld\n", ftell(fp3));
    // fsetpos(fp3, &pos_temp);
    // printf("file position indicator: %ld\n", ftell(fp3));
    // rewind(fp3);
    // fprintf(fp3, "%d", 123456789);
    // fclose(fp3);
    
    // FILE *fp4 = fopen("new_text.txt", "rb");
    // if(fp4 == NULL) {
    //     perror("file not found");
    //     return 1;
    // }
    // unsigned char store[10] = {};
    // size_t bytes_read = fread(store, sizeof(unsigned char), 5, fp4);
    // if(bytes_read != 5) {
    //     fprintf(stderr, "fread() failed: %zu", bytes_read);
    //     exit(EXIT_FAILURE);
    // }
    // FILE *fp5 = fopen("new_text_store.txt", "wb");
    // if(fp5 == NULL) {
    //     perror("file not found");
    //     return 1;
    // }
    // for(int i = 0; i < 5; i++) {
    //     printf("%02x ", store[i]);
    // }
    // printf("\n");
    // fwrite(store, 1, 5, fp5);
    // fclose(fp4);
    // fclose(fp5);

    //---------------------------------------------------------------------------
    // FILE *source, *dest;
    // source = fopen("new_text.txt", "rb");
    // dest = fopen("textfile.txt", "wb");
    // if(source == NULL || dest == NULL) {
    //     perror("Error opening files");
    //     if(source == NULL) {
    //         fclose(dest);
    //     } else if(dest == NULL) {
    //         fclose(source);
    //     }
    //     return 1;
    // }
    // int byte;
    // // while((byte = fgetc(source)) != EOF) {
    // //     printf("%02x ", byte);
    // //     fwrite(&byte, 1, 1, dest);
    // // }
    // // printf("\n");
    // while((byte = fgetc(source)) != EOF) {
    //     fputc(byte, dest);
    // }
    // fclose(source);
    // fclose(dest);
    //---------------------------------------------------------------------------
    struct Person person1 = {.age = 26, .name = "Kristijan Hornung", .residence = "California"};
    printf("%s\n", person1.name);
    printf("%s\n", person1.residence);
    struct Person *person2 = (struct Person*) malloc(sizeof(struct Person));
    strcpy(person2 -> name, "Alexa Q");
    person2 -> age = 31;
    printf("%s\n", person2 -> name);
    printf("%d\n", person2 -> age);
    strncpy(person2 -> residence, "California", sizeof("California"));
    printf("%s\n", person2 -> residence);

    char *file = "textfile.txt";
    FILE *fp6 = fopen(file, "wb");
    if(fp6 == NULL) {
        perror("error opening file");
        return 1;
    }
    size_t written = fwrite(&person1, sizeof(struct Person), 1, fp6);
    fclose(fp6);
    free(person2);
    return 0;
}