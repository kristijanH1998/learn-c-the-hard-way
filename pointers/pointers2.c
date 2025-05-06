#include <stdio.h>

void print_names_ages(int *ages, char **names, int count);
void print_different_way(int *ages, char **names, int count);
void print_cl_args(int argc, char* argv[]);

int main(int argc, char* argv[]) {
    int *ages = (int[]){23, 43, 12, 89, 2};
    char **names = (char*[]){
        "Alan", "Frank", "Mary", "John", "Lisa"
    };
    int count = 5;
    printf("Number of people: %d\n", count);
    int i = 0;
    // for(i = 0; i < count; i++) {
    //     printf("%s has %d years alive.\n", *(names + i), *(ages + i));
    // }
    print_names_ages(ages, names, count);

    printf("---\n");
    int *cur_age = ages;
    char **cur_name = names;

    // for(i = 0; i < count; i++) {
    //     printf("%s is %d years old.\n", cur_name[i], cur_age[i]);
    // }
    print_names_ages(cur_age, cur_name, count);

    printf("---\n");
    // for(i = 0; i < count; i++) {
    //     printf("%s is %d years old again.\n", *(cur_name + i), *(cur_age + i));
    // }
    i = 0;
    while(i < count) {
        printf("%s is %d years old again.\n", *(cur_name + i), *(cur_age + i));
        i++;
    }

    printf("---\n");
    // for(cur_name = names, cur_age = ages; (cur_name - names) < count; cur_name++, cur_age++) {
    //     printf("%s lived %d years so far.\n", *cur_name, *cur_age);
    // }
    print_different_way(ages, names, count);

    // for(i = 1; i < argc; i++) {
    //     printf("%s\n", *(argv + i));
    // }
    print_cl_args(argc, argv);

    printf("Value of i: %d\n", i);
    printf("Address of i: %lx\n", &i);
    printf("Value of what ages points to: %d\n", *ages);
    printf("Address of what ages points to: %lx\n", ages);
    printf("Address of ages: %lx\n", &ages);

    // for(i = 0; i < count; i++) {
    //     printf("%p ", ages + i);
    //     printf("%p ", names + i);
    // }

    i = 0;
    while(i < count) {
        printf("%p ", ages + i);
        printf("%p ", names + i);
        i++;
    }

    printf("\n");

    return 0;
}

void print_names_ages(int *ages, char **names, int count) {
    int i = 0;
    while(i < count) {
        printf("%s is %d years old.\n", *(names + i), *(ages + i));
        i++;
    }
    // for(int i = 0; i < count; i++) {
    //     printf("%s is %d years old.\n", *(names + i), *(ages + i));
    // }
}

void print_different_way(int *ages, char **names, int count) {
    char **cur_name = names;
    int *cur_age = ages;
    // for(; ((cur_name - names) < count) && ((cur_age - ages) < count); cur_name++, cur_age++) {
    //     printf("%s lived %d years so far.\n", *cur_name, *cur_age);
    // }
    while((cur_name - names) < count && (cur_age - ages) < count) {
        printf("%s lived %d years so far.\n", *cur_name, *cur_age);
        cur_name++;
        cur_age++;
    }
}

void print_cl_args(int argc, char *argv[]) {
    int i = 0;
    while(i < argc) {
        printf("%s\n", *(argv + i));
        i++;
    }
    // for(int i = 1; i < argc; i++) {
    //     printf("%s\n", *(argv + i));
    // }
}

