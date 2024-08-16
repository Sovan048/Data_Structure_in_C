// Create and perform different operations on Double-ended Queues using Linked List implementation.

#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Define the Deque structure
typedef struct Deque {
    Node* front;
    Node* rear;
} Deque;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to initialize an empty deque
Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    return dq;
}

// Check if the deque is empty
int isEmpty(Deque* dq) {
    return dq->front == NULL;
}

// Insert at the front of the deque
void insertFront(Deque* dq, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        newNode->next = dq->front;
        dq->front->prev = newNode;
        dq->front = newNode;
    }
}

// Insert at the rear of the deque
void insertRear(Deque* dq, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        newNode->prev = dq->rear;
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
}

// Delete from the front of the deque
void deleteFront(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty, cannot delete from front.\n");
        return;
    }
    Node* temp = dq->front;
    dq->front = dq->front->next;
    if (dq->front != NULL) {
        dq->front->prev = NULL;
    } else {
        dq->rear = NULL; // Deque is empty now
    }
    free(temp);
}

// Delete from the rear of the deque
void deleteRear(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty, cannot delete from rear.\n");
        return;
    }
    Node* temp = dq->rear;
    dq->rear = dq->rear->prev;
    if (dq->rear != NULL) {
        dq->rear->next = NULL;
    } else {
        dq->front = NULL; // Deque is empty now
    }
    free(temp);
}

// Display the elements of the deque
void displayDeque(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }
    Node* temp = dq->front;
    printf("Deque elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate operations with user input
int main() {
    Deque* dq = createDeque();
    int choice, data;

    while (1) {
        printf("\nDeque Operations Menu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display Deque\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertFront(dq, data);
                break;
            case 2:
                printf("Enter data to insert at rear: ");
                scanf("%d", &data);
                insertRear(dq, data);
                break;
            case 3:
                deleteFront(dq);
                break;
            case 4:
                deleteRear(dq);
                break;
            case 5:
                displayDeque(dq);
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
