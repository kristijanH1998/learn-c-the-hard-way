#include <stdio.h>
#include <stdlib.h>

struct Element {
    struct Element *next;
    int value;
};

struct Stack {
    struct Element *top;
    int size;
};

void push(struct Stack *stack, struct Element *el) {
    el->next = stack->top;
    stack->top = el;
    stack->size++;
}

struct Element *pop(struct Stack *stack) {
    struct Element *temp = malloc(sizeof(struct Element));
    temp = stack->top;
    if(stack->top->next) {
        stack->top = stack->top->next;
        temp->next = NULL;
    } else {
        stack->top = NULL;
    }
    stack->size--;
    return temp;
}

struct Element *peek(struct Stack *stack) {
    if(stack->top) {
        printf("%d\n", stack->top->value);
        return stack->top;
    } else {
        return NULL;
    }
}

int isEmpty(struct Stack *stack) {
    return (stack->size == 0);
}

int main (int argc, char *argv[]) {
    struct Stack *stack = malloc(sizeof(struct Stack));
    stack->size = 0;
    stack->top = NULL;
    struct Element *el1 = malloc(sizeof(struct Element));
    el1->next = NULL;
    el1->value = 14;
    push(stack, el1);
    struct Element *el2 = malloc(sizeof(struct Element));
    el2->next = NULL;
    el2->value = 3;
    push(stack, el2);
    peek(stack);
    pop(stack);
    peek(stack);
    printf("%d\n", isEmpty(stack));
    pop(stack);
    printf("%d\n", isEmpty(stack));
    // peek(stack);
    return 0;
}


