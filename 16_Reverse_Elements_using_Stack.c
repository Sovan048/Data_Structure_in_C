// WAP to reverse the order of the elements in the stack using additional stack.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Define the maximum size of the stack

typedef struct {
    int top;
    int items[MAX];
} Stack;

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to push an item onto the stack
void push(Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack is full!\n");
        return;
    }
    s->items[++(s->top)] = item;
}

// Function to pop an item from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1; // Return a sentinel value
    }
    return s->items[(s->top)--];
}

// Function to get the top item of the stack without removing it
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1; // Return a sentinel value
    }
    return s->items[s->top];
}

// Function to reverse the stack using an additional stack
void reverseStack(Stack *original) {
    Stack temp;
    initStack(&temp);

    // Move all items from the original stack to the temp stack
    while (!isEmpty(original)) {
        push(&temp, pop(original));
    }

    // Move all items back to the original stack
    while (!isEmpty(&temp)) {
        push(original, pop(&temp));
    }
}

// Function to print the stack
void printStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->items[i]);
    }
}

int main() {
    Stack s;
    initStack(&s);

    // Push some elements onto the stack
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);

    printf("Original stack:\n");
    printStack(&s);

    // Reverse the stack
    reverseStack(&s);

    printf("\nReversed stack:\n");
    printStack(&s);

    return 0;
}
