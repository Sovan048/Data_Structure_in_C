// Perform Stack operations using Linked List implementation.

#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to check if the stack is empty
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Function to push an element onto the stack
void push(struct Node** top, int data) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack overflow\n");
        exit(1);
    }
    newNode->data = data;   // Assign data to the new node
    newNode->next = *top;   // Point new node to the current top
    *top = newNode;         // Update top to the new node
    printf("%d pushed to stack\n", data);
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack underflow\n");
        exit(1);
    }
    struct Node* temp = *top;  // Temporary pointer to the current top
    int popped = temp->data;   // Store the data to return
    *top = (*top)->next;       // Move top to the next node
    free(temp);                // Free the memory of the old top
    return popped;
}

// Function to get the top element of the stack
int peek(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return top->data;
}

// Main function to test the stack operations
int main() {
    struct Node* top = NULL;

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    printf("%d popped from stack\n", pop(&top));
    printf("Top element is %d\n", peek(top));

    return 0;
}
