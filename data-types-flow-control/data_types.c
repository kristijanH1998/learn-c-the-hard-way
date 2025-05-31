#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Order {FIRST = 4, SECOND, THIRD = 7};

typedef void (*fptr) (char *str);

void func1 (char *str) {
    printf("%s\n", str);
}

// throws error due to const variable being changed
// void changer(const float *fp) {
//     *fp = 2.2;
// }

int main(int argc, char *argv[]) {
    int num1 = 9;
    double num2 = 292993832.2332;
    float num3 = 12.1;
    char ch1 = 'q';
    char *str = "string...,\0";
    func1(str);
    enum Order ord = SECOND;
    enum Order ord2 = FIRST;
    enum Order ord3 = THIRD;
    printf("%d\n", ord);
    printf("%d\n", ord2);
    printf("%d\n", ord3);
    unsigned int uns1 = 43;
    unsigned int uns2 = -43;
    signed int uns3 = -33;
    printf("%d\n", uns1);
    printf("%d\n", uns2);
    printf("%d\n", uns3);
    long double dbl1 = 332.332;
    short sh1 = 11112.1;
    printf("%Lf\n", dbl1);
    printf("%hd\n", sh1);
    printf("Sizes (in bytes): \n");
    printf("Integer: %d\n", sizeof num1);
    printf("Double: %d\n", sizeof num2);
    printf("Float: %d\n", sizeof num3);
    printf("Character: %d\n", sizeof ch1);
    printf("Character pointer \"str\": %d\n", sizeof str);
    printf("First character in string \"str\": %d\n", sizeof(*str));
    printf("String \"str\": %d\n", strlen(str));
    fptr ptr1 = &func1;
    printf("Function pointer: %d\n", sizeof(ptr1));
    void *some_ptr = NULL;
    printf("Pointer to anything: %d\n", sizeof(some_ptr));
    const float cns = 3.5;
    // changer(&cns);
    printf("%f\n", cns);
    printf("%d\n", cns);
    volatile char vltch = 'E';
    printf("%d\n", sizeof(vltch));
    printf("%c\n", vltch);
    register volatile const int weird = 32;
    printf("%d\n", weird);
    printf("%d\n", sizeof(weird));
    int cast_test = (int)3.3 + uns2 + (int)num3;
    printf("%d\n", cast_test);
    printf("Now time for some exact-sized integers...\n");
    int8_t int8 = 4;
    uint16_t uint16 = 223;
    printf("%d\n", int8);
    printf("%lu\n", uint16);
    printf("8-bits long integer has a size in bytes of: %d\n", sizeof(int8));
    printf("16-bits long unsigned integer has a size in bytes of: %d\n", sizeof(uint16));
    int64_t int64 = 1234567891234567891;
    uint32_t uint32 = 123456789;
    printf("%lu\n", int64);
    printf("%d\n", uint32);
    printf("%d\n", INT8_MAX);
    printf("%d\n", INT16_MAX);
    printf("%d\n", INT32_MAX);
    printf("%ld\n", INT64_MAX);
    printf("%d\n", INT8_MIN);
    printf("%d\n", INT16_MIN);
    printf("%d\n", INT32_MIN);
    printf("%ld\n", INT64_MIN);
    printf("%d\n", sizeof(INT16_MAX));
    printf("%d\n", sizeof(INT32_MIN));
    printf("%d\n", sizeof(INT64_MAX));
    printf("%d\n", sizeof(int64));
    printf("%d\n", sizeof(uint32));
    printf("%d\n", (int_least8_t)2);
    printf("%d\n", sizeof(INT_FAST64_MAX));
    intptr_t iptr;
    printf("%d\n", sizeof(iptr));
    intmax_t intmax = 9223372036854775807;
    // intmax2 is too large
    intmax_t intmax2 = 9223372036854775808;
    printf("%ld\n", intmax);
    printf("%ld\n", intmax2);
    printf("%ld\n", INTPTR_MAX);
    printf("%ld\n", INTPTR_MIN);
    printf("%ld\n", INTMAX_MAX);
    printf("%ld\n", INTMAX_MIN);
    printf("%d\n", SIZE_MAX);
    size_t intsize = sizeof((int) 6);
    printf("%d\n", intsize);
    return 0;
}