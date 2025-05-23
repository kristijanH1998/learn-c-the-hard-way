#include <stdio.h>
#include <ctype.h>
#include <string.h>

int can_print_it(char ch);
void print_letters(char arg[], int len);
void print_digits(char arg[], int len);

void print_arguments(int argc, char *argv[]) 
{
    int i = 0;
    for(i = 0; i < argc; i++) {
        print_letters(argv[i], strlen(argv[i]));
        // print_digits(argv[i], strlen(argv[i]));
    }
}

void print_letters(char arg[], int len) {
    int i = 0;
    for(i = 0; i < len; i++) {
        char ch = arg[i];
        // if(isalpha(ch) || isblank(ch)) {
        //     printf("'%c' == %d ", ch, ch);
        // }
        if(isdigit(ch)) {
            printf("'%c' == %d ", ch, ch);
        }
    }
    printf("\n");
}

// void print_digits(char arg[], int len) {
//     int i = 0;
//     for(i = 0; i < len; i++) {
//         char ch = arg[i];
//         if(isdigit(ch)) {
//             printf("'%c' == %d ", ch, ch);
//         }
//     }
//     printf("\n");
// }

// int can_print_it(char ch) {
//     return isalpha(ch) || isblank(ch);
// }

int main(int argc, char *argv[]) {
    // print_arguments(argc + 1, argv);
    print_arguments(argc, argv);
    return 0;
}



