#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

#define MAX_DATA 100

typedef enum EyeColor {
    BLUE_EYES, GREEN_EYES, BROWN_EYES, BLACK_EYES, OTHER_EYES
} EyeColor;

const char *EYE_COLOR_NAMES[] = {
    "Blue", "Green", "Brown", "Black", "Other"
};

typedef struct Person {
    int age;
    char first_name[MAX_DATA];
    char last_name[MAX_DATA];
    EyeColor eyes;
    float income;
} Person;

int main(int argc, char *argv[]) {
    Person you = { .age = 0 };
    int i = 0;
    char *in = NULL;
    int rc = 0; 

    printf("What's your First Name? ");
    // in = fgets(you.first_name, MAX_DATA - 1, stdin);
    // gets(you.first_name);
    // rc = fscanf(stdin, "%50s", you.first_name);  
    // check(in != NULL, "Failed to read first name.");
    rc = scanf("%50s", you.first_name);
    check(rc > 0, "Failed to read first name.");

    printf("What's your Last Name? ");
    // in = fgets(you.last_name, MAX_DATA - 1, stdin);
    // gets(you.last_name);
    // rc = fscanf(stdin, "%50s", you.last_name);
    // check(in != NULL, "Failed to read last name.");
    rc = scanf("%50s", you.last_name);
    check(rc > 0, "Failed to read last name.");

    printf("How old are you? ");
    // rc = fscanf(stdin, "%d", &you.age);
    char buf[MAX_DATA];
    rc = scanf("%d", &you.age);
    check(rc > 0, "You have to enter a number.");
    // in = fgets(buf, MAX_DATA - 1, stdin);
    // check(in != NULL, "Failed to read age.");
    // you.age = atoi(buf);

    printf("What color are your eyes:\n");
    for(int i = 0; i <= OTHER_EYES; i++) {
        printf("%d) %s\n", i + 1, EYE_COLOR_NAMES[i]);
    }
    printf("> ");

    int eyes = -1;
    // rc = fscanf(stdin, "%d", &eyes);
    rc = scanf("%d", &eyes);
    check(rc > 0, "You have to enter a number.");
    // in = fgets(buf, MAX_DATA - 1, stdin);
    // check(in != NULL, "Failed to read eye color.");
    // eyes = atoi(buf);
    you.eyes = eyes - 1;
    check(you.eyes <= OTHER_EYES && you.eyes >= 0, "Do it right, that's not an option.");
    
    printf("How much do you make an hour? ");
    // rc = fscanf(stdin, "%f", &you.income);
    rc = scanf("%f", &you.income);
    check(rc > 0, "Enter a floating point number.");
    // in = fgets(buf, MAX_DATA - 1, stdin);
    // check(in != NULL, "failed to read income");
    // you.income = atof(buf);

    printf("-------RESULTS-------\n");
    printf("First Name: %s\n", you.first_name);
    printf("Last Name: %s\n", you.last_name);
    printf("Age: %d\n", you.age);
    printf("Eyes: %s\n", EYE_COLOR_NAMES[you.eyes]);
    printf("Income: %f\n", you.income);
    return 0;
error:
    return -1;
}