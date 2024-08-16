// Perform Queues operations using Circular Array implementation

#include <stdio.h>
#include <stdbool.h>

#define SIZE 5  // Define the maximum size of the queue

typedef struct {
    int items[SIZE];
    int front;
    int rear;
} CircularQueue;

// Initialize the queue
void initializeQueue(CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
bool isFull(CircularQueue* q) {
    return (q->front == (q->rear + 1) % SIZE);
}

// Check if the queue is empty
bool isEmpty(CircularQueue* q) {
    return (q->front == -1);
}

// Add an element to the queue
void enqueue(CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    
    if (isEmpty(q)) {
        q->front = 0;
    }
    
    q->rear = (q->rear + 1) % SIZE;
    q->items[q->rear] = value;
    printf("Enqueued %d\n", value);
}

// Remove an element from the queue
int dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % SIZE;
    }
    printf("Dequeued %d\n", item);
    return item;
}

// Peek at the front element
int peek(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Nothing to peek.\n");
        return -1;
    }
    return q->items[q->front];
}

// Display the queue
void displayQueue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    
    int i = q->front;
    printf("Queue: ");
    while (true) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function to demonstrate queue operations with user input
int main() {
    CircularQueue q;
    initializeQueue(&q);
    
    int choice, value;
    
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                value = peek(&q);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
            case 4:
                displayQueue(&q);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
