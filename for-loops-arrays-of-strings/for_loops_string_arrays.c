#include <stdio.h>

int main(int argc, char *argv[]) {
    int i = 0;
    char *states[] = {"California", "Oregon", "Washington", "Texas", NULL};
    int num_of_states = 5;
    states[3] = argv[0];
    states[4] = argv[1];
    for(i = 0; i < num_of_states; i++) {
        printf("state %d: %s\n", i, states[i]);
    }
    argv[1] = states[0];
    argv[2] = states[0];
    for(i = 0; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }
    return 0;
}