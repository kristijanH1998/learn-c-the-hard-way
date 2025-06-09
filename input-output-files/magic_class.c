// this is a program from Library Functions Manual for printing magic and class of an ELF executable /bin/sh
#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

int main(int argc, char *argv[]) {
    FILE *fp;
    size_t ret;
    unsigned char buffer[4];

    fp = fopen("/bin/sh", "rb");
    if(!fp) {
        fprintf(stderr, "fread() failed: %zu\n", ret);
        exit(EXIT_FAILURE);
    }
    ret = fread(buffer, sizeof(*buffer), ARR_SIZE(buffer), fp);
    if(ret != ARR_SIZE(buffer)) {
        fprintf(stderr, "fread() failed: %zu\n", ret);
        exit(EXIT_FAILURE);
    }
    printf("ELF magic: %#04x%02x%02x%02x\n", buffer[0], buffer[1], buffer[2], buffer[3]);
    ret = fread(buffer, 1, 1, fp);
    if(ret != 1) {
        fprintf(stderr, "fread() failed: %zu\n", ret);
        exit(EXIT_FAILURE);
    }
    printf("Class: %#04x\n", buffer[0]);
    fclose(fp);
    exit(EXIT_SUCCESS);
}