#include <stdio.h>

int main() {
    char full_name[] = {
        'K', 'r', 'i', 's', 't', 'i', 'j', 'a', 'n',
        ' ', 'H', 'o', 'r', 'n', 'u', 'n', 'g'/*, '\0'*/ 
    };
    char name[] = "Kristijan";
    int areas[] = {100, name[3], 13, 14, 20};
    
    printf("The size of an int: %ld\n", sizeof(int));
    printf("The size of areas (int[]): %ld\n", sizeof(areas));
    printf("The number of ints in areas: %ld\n", sizeof(areas) / sizeof(int));
    printf("The first area is %d, the second is %d.\n", areas[0], areas[1]);
    printf("The size of char: %ld\n", sizeof(char));
    printf("The size of name (char[]): %ld\n", sizeof(name));
    printf("The number of chars in name: %ld\n", sizeof(name) / sizeof(char));
    printf("The size of full_name(char[]): %ld\n", sizeof(full_name));
    printf("The number of chars in full_name: %ld\n", sizeof(full_name) / sizeof(char));
    printf("name=\"%s\", full_name=\"%s\"\n", name, full_name);
    printf("Far away int/char in name: %ld\n", name[300]);
    printf("Far away int/char in full_name: %ld\n", full_name[-200]);
    return 0;
}