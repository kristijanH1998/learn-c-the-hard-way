#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    const char *filename = "textfile.txt";
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        fp = fopen(filename, "w");
        if(fp == NULL) {
            perror("Error creating file.");
            return 1;
        }
        fprintf(fp, "This is a typical Hello World sentence.\n");
        fclose(fp);
        fp = fopen(filename, "r");
        if(fp == NULL) {
            perror("Error opening file.");
            return 1;
        }
    }
    char buf[100];
    while(fscanf(fp, "%s", buf) == 1) {
        // if(strcmp(buf, "\n") == 0) {
        //     printf("\n");
        // }
        printf("%s ", buf);
    }
    printf("\n");
    rewind(fp);
    while(fgets(buf, 100, fp)) {
        // if(strcmp(buf, "\n") == 0) {
        //     printf("\n");
        // }
        printf("%s ", buf);
    }
    // printf("\n");
    freopen(filename, "w", fp);
    fprintf(fp, "1.23 4.56 7.89\n");
    float fl1, fl2, fl3;
    if(fscanf(fp, "%f %f %f", &fl1, &fl2, &fl3) == 3) {
        printf("%.2f %.2f %.2f\n", fl1, fl2, fl3);
    }
    fclose(fp);
    // remove(filename);


    return 0;
}