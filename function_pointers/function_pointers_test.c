#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int tester(int a, int b) {
    return a + b;
}

int tester2(int num1, int num2) {
    return num1 * num2;
}

double tester3(double num1, double num2) {
    return pow(num1, num2);
}

int (*fp) (int, int);
double (*fp2) (double first, double second);

int main (int argc, char *argv[]) {
    // int (*tester) (int a, int b) = sorted_order;
    fp = &tester;
    printf("%d is the same as %d\n", tester(2, 4), fp(2, 4));
    fp = &tester2;
    printf("%d is the same as %d\n", tester2(2, 4), fp(2, 4));
    fp2 = tester3;
    printf("%f is the same as %d\n", tester3(2, 4), (int)fp2(2, 4));
    return 0;
}

/*
In C, a function pointer is declared with a syntax resembling that of a function prototype, but with an asterisk * before the function name and the name enclosed in parentheses. This indicates that the variable is a pointer to a function.
The general form of a function pointer declaration is:
C

return_type (*pointer_name)(parameter_list);

    return_type: The data type returned by the function.
    pointer_name: The name of the function pointer variable.
    parameter_list: A comma-separated list of the data types of the function's parameters.

For example, if there is a function:
C

int add(int a, int b) {
    return a + b;
}

A pointer to this function would be declared as:
C

int (*add_ptr)(int, int);

Here, add_ptr is a pointer that can point to any function that takes two integers as arguments and returns an integer. It can be assigned the address of the add function:
C

add_ptr = add; // or add_ptr = &add;

The function can then be called using the pointer:
C

int sum = add_ptr(5, 3);
*/