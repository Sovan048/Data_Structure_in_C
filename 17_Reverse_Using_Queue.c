// WAP to reverse the order of the elements in the stack using additional Queue.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack implementation
typedef struct {
    int top;
    int arr[MAX];
} Stack;

// Queue implementation
typedef struct {
    int front, rear, size;
    int arr[MAX];
} Queue;

// Function prototypes
void initStack(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int isStackEmpty(Stack *s);
void initQueue(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int isQueueEmpty(Queue *q);
void reverseStack(Stack *s, Queue *q);

int main() {
    Stack s;
    Queue q;
    
    // Initialize stack and queue
    initStack(&s);
    initQueue(&q);
    
    // Push elements onto the stack
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);
    
    // Reverse the stack
    reverseStack(&s, &q);
    
    // Print the reversed stack
    printf("Reversed Stack:\n");
    while (!isStackEmpty(&s)) {
        printf("%d\n", pop(&s));
    }
    
    return 0;
}

// Stack functions
void initStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int value) {
    if (s->top < (MAX - 1)) {
        s->arr[++(s->top)] = value;
    } else {
        printf("Stack overflow\n");
    }
}

int pop(Stack *s) {
    if (s->top >= 0) {
        return s->arr[(s->top)--];
    } else {
        printf("Stack underflow\n");
        return -1; // Error value
    }
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

// Queue functions
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

void enqueue(Queue *q, int value) {
    if (q->size < MAX) {
        q->arr[++(q->rear)] = value;
        q->size++;
    } else {
        printf("Queue overflow\n");
    }
}

int dequeue(Queue *q) {
    if (q->size > 0) {
        q->size--;
        return q->arr[q->front++];
    } else {
        printf("Queue underflow\n");
        return -1; // Error value
    }
}

int isQueueEmpty(Queue *q) {
    return q->size == 0;
}

// Function to reverse stack using a queue
void reverseStack(Stack *s, Queue *q) {
    // Transfer elements from stack to queue
    while (!isStackEmpty(s)) {
        enqueue(q, pop(s));
    }
    
    // Transfer elements back from queue to stack
    while (!isQueueEmpty(q)) {
        push(s, dequeue(q));
    }
}
