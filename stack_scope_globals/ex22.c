#include <stdio.h>
#include "ex22.h"
#include "dbg.h"

int THE_SIZE = 1000;
static int THE_AGE = 26;
// int *THE_AGE_PTR = &THE_AGE;
// int *THE_SIZE_PTR = &THE_SIZE;

int get_age() {
    return THE_AGE;
}

void set_age(int age) {
    THE_AGE = age;
}

double update_ratio(double new_ratio) {
    static double ratio = 1.0;
    double old_ratio = ratio;
    ratio = new_ratio;
    return old_ratio;
}

void print_size() {
    log_info("I think the size is: %d", THE_SIZE);
}

// static void print_size_static() {
//     log_info("I think the size is: %d", THE_SIZE);
// }