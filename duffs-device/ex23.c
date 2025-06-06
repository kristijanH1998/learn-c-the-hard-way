#include <stdio.h>
#include <string.h>
#include <time.h>
#include "dbg.h"
#include "cases.h"

int normal_copy(char *from, char *to, int count) {
    int i = 0;
    for(i = 0; i < count; i++) {
        to[i] = from[i];
    }
    return i;
}

int duffs_device(char *from, char *to, int count) {
    {
        int n = (count + 7) / 8;
        switch(count % 8) {
            case 0:
                do {
                    *to++ = *from++;
                    case 7:
                    *to++ = *from++;
                    case 6:
                    *to++ = *from++;
                    case 5:
                    *to++ = *from++;
                    case 4:
                    *to++ = *from++;
                    case 3:
                    *to++ = *from++;
                    case 2:
                    *to++ = *from++;
                    case 1:
                    *to++ = *from++;
                } while(--n > 0);
        }
    }
    return count;
}

int duffs_device_w_macro(char *from, char *to, int count) {
    {
        int len = 32;
        int n = (count + (len - 1)) / len;
        switch(count % len) {
            case 0:
                do {
                    // while(len > 0) {
                    //     *to++ = *from++;
                    //     cases(len);
                    //     len -= 8;
                    // }
                    // len = 32;
                    *to++ = *from++;
                    cases(32);
                    *to++ = *from++;
                    cases(24);
                    *to++ = *from++;
                    cases(16);
                    *to++ = *from++;
                    cases(8);
                    // duffs_device_len_n(len > 0, len, 8);
                } while(--n > 0);
        }
    }
    return count;
}

int zeds_device(char *from, char *to, int count) {
    {
        int n = (count + 7) / 8;
        switch(count % 8) {
            case 0:
again:          *to++ = *from++;
            case 7:
                *to++ = *from++;
            case 6:
                *to++ = *from++;
            case 5:
                *to++ = *from++;
            case 4:
                *to++ = *from++;
            case 3:
                *to++ = *from++;
            case 2:
                *to++ = *from++;
            case 1:
                *to++ = *from++;
            if(--n > 0) {
                goto again;
            }
        }
    }
    return count;
}

int valid_copy(char *data, int count, char expects) {
    int i = 0;
    for(i = 0; i < count; i++) {
        if(data[i] != expects) {
            log_err("[%d] %c != %c", i, data[i], expects);
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    char from[1000] = {'a'};
    char to[1000] = {'c'};
    int rc = 0;
    memset(from, 'x', 1000);
    memset(to, 'y', 1000);
    check(valid_copy(to, 1000, 'y'), "Not initialized right.");

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    rc = normal_copy(from, to, 1000);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for normal copy in seconds: %f\n", cpu_time_used);

    check(rc == 1000, "Normal copy failed: %d", rc);
    check(valid_copy(to, 1000, 'x'), "Normal copy failed.");
    memset(to, 'y', 1000);

    start = clock();
    rc = duffs_device(from, to, 1000);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Duff's device copy in seconds: %f\n", cpu_time_used);

    check(rc == 1000, "Duff's device failed: %d", rc);
    check(valid_copy(to, 1000, 'x'), "Duff's device failed copy.");
    memset(to, 'y', 1000);

    start = clock();
    rc = zeds_device(from, to, 1000);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Zed's device copy in seconds: %f\n", cpu_time_used);

    check(rc == 1000, "Zed's device failed: %d", rc);
    check(valid_copy(to, 1000, 'x'), "Zed's device failed copy.");
    // memset(to, 'y', 1000);
    char from2[1024] = {'a'};
    char to2[1024] = {'c'};
    rc = 0;
    memset(from2, 'x', 1024);
    memset(to2, 'y', 1024);
    check(valid_copy(to2, 1024, 'y'), "Not initialized right.");

    rc = duffs_device_w_macro(from2, to2, 1024);

    check(rc == 1024, "Duff's device with macro failed: %d", rc);
    check(valid_copy(to2, 1024, 'x'), "Duff's device with macro failed copy.");

    char src[2000] = {};
    char dst[2000] = {};
    start = clock();
    memset(src, 'a', 2000);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for memset (first): %f\n", cpu_time_used);
    start = clock();
    memset(dst, 'b', 2000);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for memset (second): %f\n", cpu_time_used);

    start = clock();
    memcpy(dst, src, 2000);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for memcpy: %f\n", cpu_time_used);
    check(valid_copy(dst, 2000, 'a'), "memcpy failed to copy.");

    memset(dst, 'b', 2000);

    start = clock();
    memmove(dst, src, 2000);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for memmove: %f\n", cpu_time_used);
    check(valid_copy(dst, 2000, 'a'), "memmove failed to copy.");

    return 0;
error:
    return 1;
}