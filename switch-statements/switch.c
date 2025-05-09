#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("ERROR: You need at least one argument.\n");
        return 1;
    }
    int i = 0;
    char letter;
    int j = 1;

    for(; j < argc; j++) {
        printf("Argument %d:\n", j);
        for(i = 0, letter = argv[j][0]; argv[j][i] != '\0'; i++, letter = argv[j][i]) {
            // switch(letter) {
            //     case 'a':
            //     case 'A':
            //         printf("%d: 'A'\n", i);
            //         break;
            //     case 'e':
            //     case 'E':
            //         printf("%d: 'E'\n", i);
            //         break;
            //     case 'i':
            //     case 'I':
            //         printf("%d: 'I'\n", i);
            //         break;
            //     case 'o':
            //     case 'O':
            //         printf("%d: 'O'\n", i);
            //         break;
            //     case 'u':
            //     case 'U':
            //         printf("%d: 'U'\n", i);
            //         break;
            //     case 'y':
            //     case 'Y':
            //         printf("%d: 'Y'\n", i);
            //         break;
            //     default:
            //         printf("%d: %c is not a vowel.\n", i, letter);
            // }
            if(letter == 'a' || letter == 'A'){
                printf("%d: 'A'\n", i);
            } else if(letter == 'e' || letter == 'E') {
                printf("%d: 'E'\n", i);
            } else if(letter == 'i' || letter == 'I') {
                printf("%d: 'I'\n", i);
            } else if(letter == 'o' || letter == 'O') {
                printf("%d: 'O'\n", i);
            } else if(letter == 'u' || letter == 'U') {
                printf("%d: 'U'\n", i);
            } else if(letter == 'y' || letter == 'Y') {
                printf("%d: 'Y'\n", i);
            } else {
                printf("%d: %c is not a vowel.\n", i, letter);
            }
        }
        printf("\n");
        i = 0;
    }
    return 0;
}