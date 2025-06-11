#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "dbg.h"

#define MAX_DATA 100

enum Values {
    FIRST, SECOND, THIRD
};

int read_string(char **out_string, int max_buffer) {
    *out_string = calloc(1, max_buffer + 1);
    check_mem(*out_string);
    // char *result = fgets(*out_string, max_buffer, stdin);
    // int buf_size = max_buffer;
    char result[MAX_DATA];
    int i = 0;
    int ch;
    while(i < (max_buffer - 1)) {
        ch = fgetc(stdin);
        result[i] = (char)ch;
        *(*(out_string) + i) = (char)ch;
        if(ch == '\n') {
            break;
        }
        i++;
    }
    result[i] = '\0';
    *(*(out_string) + i) = '\0';
    check(result != NULL, "Input error.");
    return 0;
error:
    if(*out_string) free(*out_string);
    *out_string = NULL;
    return -1;
}

int read_int(long *out_int) {
    char *input = NULL;
    char *end = NULL;
    int rc = read_string(&input, MAX_DATA);
    check(rc == 0, "Failed to read number.");
    *out_int = strtol(input, &end, 10);
    check((*end == '\0' || *end == '\n') && (*input != '\0'), "Invalid number: %s", input);
    free(input);
    return 0;
error:
    if (input) free(input);
    return -1;
}

int read_scan(const char *fmt, ...) {
    int i = 0;
    int rc = 0;
    long *out_int = NULL;
    char *out_char = NULL;
    char **out_string = NULL;
    int max_buffer = 0;

    va_list argp;
    va_start(argp, fmt);
    for(i = 0; fmt[i] != '\0'; i++) {
        if(fmt[i] == '%') {
            i++;
            switch(fmt[i]){
                case '\0':
                    sentinel("Invalid format, you ended with %%.");
                    break;
                case 'd':
                    out_int = va_arg(argp, long *);
                    rc = read_int(out_int);
                    check(rc == 0, "Failed to read int.");
                    break;
                case 'c':
                    out_char = va_arg(argp, char *);
                    *out_char = fgetc(stdin);
                    break;
                case 's':
                    max_buffer = va_arg(argp, int);
                    out_string = va_arg(argp, char **);
                    rc = read_string(out_string, max_buffer);
                    check(rc == 0, "Failed to read string.");
                    break;
                default:
                    sentinel("Invalid format.");
            }
        } else {
            fgetc(stdin);
        }
        check(!feof(stdin) && !ferror(stdin), "Input error.");
    }
    va_end(argp);
    return 0;
error:
    va_end(argp);
    return -1;
}

int print_write(const char *string, ...) {
    long *write_int = NULL;
    float write_float;
    int write_ch;
    char *write_string;
    char temp_str[MAX_DATA];

    va_list argp;
    va_start(argp, string);

    for(int i = 0; string[i] != '\0'; i++) {
        if(string[i] == '%') {
            i++;
            switch(string[i]) {
                case '\0':
                    sentinel("Invalid format, you ended with %%.");
                    break;
                case 'd':
                    write_int = va_arg(argp, long *);
                    sprintf(temp_str, "%d", write_int);
                    fputs(temp_str, stdout);
                    break;
                case 'c':
                    write_ch = va_arg(argp, int); 
                    putc(write_ch, stdout);
                    break;
                case 'f':
                    write_float = va_arg(argp, double);
                    sprintf(temp_str, "%.2f", write_float);
                    fputs(temp_str, stdout);
                    break;
                case 's':
                    write_string = va_arg(argp, char *);
                    puts(write_string);
                    break;
                default:
                    sentinel("Invalid format.");
            }
        } else {
            putchar(string[i]);
        }
    }
    va_end(argp);
    return 0;
error:
    va_end(argp);
    return -1;
}

int main(int argc, char *argv[]) {
    char *first_name = NULL;
    char initial = ' ';
    char *last_name = NULL;
    long age = 0;

    // printf("What's your first name? ");
    print_write("What's your first name? ");
    int rc = read_scan("%s", MAX_DATA, &first_name);
    // // int rc = read_scan("%s", &first_name);
    // // int rc = read_scan("%s", MAX_DATA + 10, &first_name);
    check(rc == 0, "Failed first name.");

    // printf("What's your initial? ");
    print_write("What's your initial? ");
    rc = read_scan("%c\n", &initial);
    check(rc == 0, "Failed initial.");

    // printf("What's your last name? ");
    print_write("What's your last name? ");
    rc = read_scan("%s", MAX_DATA, &last_name);
    // // rc = read_scan("%s", &last_name);
    // // rc = read_scan("%s", MAX_DATA + 10, &last_name);
    check(rc == 0, "Failed last name.");

    // printf("How old are you? ");
    print_write("How old are you? ");
    rc = read_scan("%d", &age);
    check(rc == 0, "Failed to read age.");
    
    // printf("----RESULTS----\n");
    // printf("First Name: %s\n", first_name);
    // printf("Initial: '%c'\n", initial);
    // printf("Last Name: %s\n", last_name);
    // printf("Age: %d\n", age);
    print_write("----RESULTS----\n");
    print_write("First Name: %s", first_name);
    print_write("Initial: '%c'\n", initial);
    print_write("Last Name: %s", last_name);
    print_write("Age: %d\n", age);
    
    free(first_name);
    free(last_name);

    // print_write("Hello %d %d %d\n", 20, 13, 11);
    // char c1 = '3';
    // char c2 = 'e';
    // print_write("%c hi %c\n", c1, c2);
    // print_write("an integer: %d  and a character: %c\n", 400, 'Y');
    // print_write("a float number: %f\n", 5.67);
    // enum Values value1 = FIRST;
    // print_write("an enumerated value: %d\n", value1);
    // print_write("an enumerated value: %d\n", THIRD);
    // print_write("printing a string: %s", "some sentence...");
    return 0;
error:
    return -1;
}