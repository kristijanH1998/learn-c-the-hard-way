#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int i = 0;

    if(argc <= 2) {
        printf("You only have one argument. You suck.\n");
    } else if(argc > 2 && argc < 4) {
        printf("Here are your arguments:\n");
        for(; i < argc; i++){
            printf("%s ", argv[i]);
        }
        printf("\n");
    } else if(argc > 1 && (strcmp(argv[1], "arg1") == 0)) {
        printf("Nice!\n");
    }
    
    /* else {
        printf("You have too many arguments.");
    } */
    return 0;
}