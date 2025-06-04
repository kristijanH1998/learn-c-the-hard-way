#include "ex22.h"
#include "dbg.h"
// #include <string.h>

const char *MY_NAME = "Kristijan Hornung";

void scope_demo(int count) {
    log_info("count is: %d", count);
    if(count > 10) {
        int count = 100;
        log_info("count in this scope is %d", count);
    }
    log_info("count is at exit: %d", count);
    count = 3000;
    log_info("count after assign: %d", count);
    // scope_demo(count);
}

void passVal(float num) {
    num += 4.5;
    printf("flnum inside passVal equals: %f\n", num);
}

void passRef(float *num) {
    (*num) += 4.5;
    printf("flnum inside passRef equals: %f\n", (*num));
}

int main(int argc, char *argv[]) {
    log_info("My name: %s, age: %d", MY_NAME, get_age());
    set_age(100);
    log_info("My age is now: %d", get_age());
    log_info("THE_SIZE is: %d", THE_SIZE);
    print_size();
    THE_SIZE = 9;
    log_info("THE SIZE is now: %d", THE_SIZE);
    print_size();
    log_info("Ratio at first: %f", update_ratio(2.0));
    log_info("Ratio again: %f", update_ratio(10.0));
    log_info("Ratio once more: %f", update_ratio(300.0));
    int count = 4;
    scope_demo(count);
    scope_demo(count * 20);
    log_info("count after calling scope_demo: %d", count);
    
    // both of these print address at which update_ratio() starts (.text section of the program, due to PIE it's different for each execution)
    // printf("%p\n", update_ratio);
    // printf("%p\n", &update_ratio);
    // printf("%f\n", *(&update_ratio+0x8));
    // printf("%f\n", *(&update_ratio+0x18));
    // printf("%f\n", *(&update_ratio+0x20));
    // THE_AGE is static in ex22.c so it's not accessible from here
    // printf("%d\n", THE_AGE);
    // but THE_SIZE is visible
    // printf("%d\n", THE_SIZE);
    // both old_ratio and ratio are local to update_ratio() and therefore inaccessible from here by direct way, but since update_ratio() returns it we can see it that way
    // printf("%f\n", old_ratio);
    // printf("%f\n", ratio);
    // const char name[5] = "Kiki";
    // printf("%s\n", name);
    // char *new_name = "ikiK";
    // strcpy(name, new_name);
    // printf("%s\n", name);
    // const int testnum = 20;
    // testnum = 11;
    // printf("%d\n", testnum);
    // print_size_static();
    float flnum = 2.0f;
    passVal(flnum);
    printf("flnum after passVal: %f\n", flnum);
    passRef(&flnum);
    printf("flnum after passRef: %f\n", flnum);
    // printf("%d\n", *THE_AGE_PTR);
    // printf("%d\n", *THE_SIZE_PTR);

    return 0;
}

