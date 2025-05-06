#include <stdio.h>

int main(int argc, char* argv[]) {
    int ages[] = {23, 43, 12, 89, 2};
    char *names[] = {
        "Alan", "Frank", "Mary", "John", "Lisa"
    };
    int count = sizeof(ages) / sizeof(int);
    int i = 0;
    // for(i = 0; i < count; i++) {
    //     printf("%s has %d years alive.\n", names[i], ages[i]);
    // }

    for(i = (count - 1); i >= 0; i--) {
        printf("%s has %d years alive.\n", names[i], ages[i]);
    }

    printf("---\n");
    int *cur_age = ages;
    // int *cur_age = (int *)names;               this will cause undefined behavior

    char **cur_name = names;

    // for(i = 0; i < count; i++) {
    //     printf("%s is %d years old.\n", *(cur_name + i), *(cur_age + i));
    // }

    for(i = (count - 1); i >= 0; i--) {
        printf("%s is %d years old.\n", *(cur_name + i), *(cur_age + i));
    }

    printf("---\n");
    // for(i = 0; i < count; i++) {
    //     printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
    // }

    for(i = (count - 1); i >= 0; i--) {
        printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
    }

    printf("---\n");
    // for(cur_name = names, cur_age = ages; (cur_name - names) < count; cur_name++, cur_age++) {
    //     printf("%s lived %d years so far.\n", *cur_name, *cur_age);
    // }

    for(cur_name = (names + count - 1), cur_age = (ages + count - 1); cur_name >= names; cur_name--, cur_age--) {
        printf("%s lived %d years so far.\n", *cur_name, *cur_age);
    }

    // for(cur_name = names - 1, cur_age = ages - 1; (cur_name - names) <= count; cur_name++, cur_age++) {
    //     printf("%s lived %d years so far.\n", *cur_name, *cur_age);
    // }

    printf("Number of ages in ages[]: %d\n", sizeof(ages) / sizeof(int));
    printf("Size of names[]: %d\n", sizeof(names));
    printf("Number of names in names[]: %d\n", sizeof(names) / sizeof(char*));

    return 0;
}