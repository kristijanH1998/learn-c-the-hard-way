#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *message) {
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }
    exit(1);
}

typedef int (*compare_cb) (int a, int b);
typedef int* (*sorting_func) (int *arr, int b, int c, compare_cb cmp);

// this Merge Sort algorithm is from https://www.programiz.com/dsa/merge-sort
void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], M[n2];

    for(int i = 0; i < n1; i++){
        L[i] = arr[p + i];
    }
    for(int j = 0; j < n2; j++) {
        M[j] = arr[q + 1 + j];
    }
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    while(i < n1 && j < n2) {
        if(L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

int *mergeSort(int arr[], int l, int r, compare_cb cmp) {
    int *target;
    if(cmp(l, r) < 0) {
        target = malloc((r - l + 1) * sizeof(int));
        if(!target)
            die("Memory error.");
        memcpy(target, arr, (r - l + 1) * sizeof(int));
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, cmp);
        mergeSort(arr, m + 1, r, cmp);
        merge(arr, l, m, r);
    }
    // if(l < r){
        
    // }
    return target;
}

int *bubble_sort(int *numbers, int count, int temp, compare_cb cmp) {
    // int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int));
    if(!target)
        die("Memory error.");
    memcpy(target, numbers, count * sizeof(int));
    for(i = 0; i < count; i++) {
        for(j = 0; j < count - 1; j++) {
            if(cmp(target[j], target[j + 1]) > 0) {
                temp = target[j + 1];
                target[j + 1] = target[j];
                target[j] = temp;
            }
        }
    }
    return target;
}

int sorted_order(int a, int b) {
    return a - b;
}

int reverse_order(int a, int b) {
    return b - a;
}

int strange_order(int a, int b) {
    if(a == 0 || b == 0) {
        return 0;
    } else {
        return a % b;
    }
}

double wrong_func(int a, double b) {
    return (double) a - b;
}

void test_sorting(int *numbers, int count, sorting_func func, compare_cb cmp) {
    int i = 0;
    int *sorted;
    if(*func == &mergeSort) {
        sorted = func(numbers, 0, count - 1, cmp);
    } else {
        sorted = func(numbers, count, 0, cmp);
    }
    // int *sorted = func(numbers, count, 0, cmp);
    // int *sorted_merge = sorting_func(numbers, 0, count - 1, cmp);
    if(!sorted) {
        die("Failed to sort as requested.");
    }
    for(i = 0; i < count; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");
    free(sorted);

    //breaking the program example:
    // unsigned char *data = (unsigned char *)cmp;
    // for(i = 0; i < 25; i++) {
    //     printf("%02x:", data[i]);
    // }
    // printf("\n");
}

int main(int argc, char *argv[]) {
    printf("Hi this is just some sentence with newline char at the end.\n");
    if(argc < 2) die("USAGE: ex18 4 3 1 5 6");
    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1;
    int *numbers = malloc(count * sizeof(int));
    if(!numbers) die("Memory error.");
    for(i = 0; i < count; i++) {
        numbers[i] = atoi(inputs[i]);
    }
    test_sorting(numbers, count, bubble_sort, sorted_order);
    test_sorting(numbers, count, bubble_sort, reverse_order);
    // test_sorting(numbers, count, bubble_sort, strange_order);
    test_sorting(numbers, count, mergeSort, sorted_order);
    test_sorting(numbers, count, mergeSort, sorted_order);
    test_sorting(numbers, count, mergeSort, sorted_order);
    // test_sorting(numbers, count, mergeSort, reverse_order);
    // test_sorting(numbers, count, mergeSort, strange_order);
    
    // this call would throw compiler error because function pointer sent here is not pointing to a function compatible with compare_cb function pointer type 
    // test_sorting(numbers, count, &wrong_func);
    
    // this will also crash the program
    // test_sorting(numbers, count, NULL);

    free(numbers);
    printf("Hello my name is Kristijan.\n");
    return 0;
}