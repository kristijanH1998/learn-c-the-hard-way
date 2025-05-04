#include <stdio.h>

int main(int argc, char* argv[]){
    int numbers[4] = { 0 };
    // char name[4] = { 'a', 'a', 'a', 'a' /*, 'a' */};
    char *name = "aaaa";
    printf("numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
    printf("name each: %c %c %c %c %c\n", name[0], name[1], name[2], name[3], name[4]);
    printf("name: %s\n", name);
    numbers[0] = 'k';
    numbers[1] = 'r';
    numbers[2] = 'i';
    numbers[3] = 's';
    // name[0] = 6;
    // name[1] = 7;
    // name[2] = 8;
    // // name[3] = 'A';
    // name[3] = '\0';
    printf("numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
    printf("name each: %c %c %c %c\n", name[0], name[1], name[2], name[3]);
    printf("name: %s\n", name);
    char *another = "Kristijan";
    printf("My name: %s\n", another);
    int i = 0;
    printf("My name each: ");
    while(another[i] != '\0') {
        printf("%c ", another[i++]);
    }
    for(int j = 0; j < 4; j++) {
        printf("%d ", numbers[j]);
    }
    printf("\n");
    printf("%d\n", name);
    printf("%x\n", name);
    return 0;
}