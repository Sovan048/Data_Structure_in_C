// Implement Circular Linked List. Include functions for insertion, deletion and search of a number, reverse the list

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to insert at the end of the list
void insert(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head;
    newNode->data = data;
    newNode->next = *head;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        while (last->next != *head)
            last = last->next;
        last->next = newNode;
    }
}

// Function to delete a node with a given value
void deleteNode(struct Node **head, int key) {
    if (*head == NULL) return;

    struct Node *curr = *head, *prev;
    if ((*head)->data == key) {
        prev = *head;
        while (prev->next != *head)
            prev = prev->next;
        if (*head == (*head)->next) {
            free(*head);
            *head = NULL;
        } else {
            prev->next = curr->next;
            *head = prev->next;
            free(curr);
        }
        return;
    }

    while (curr->next != *head && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr->data == key) {
        prev->next = curr->next;
        free(curr);
    }
}

// Function to search for a node with a given value
int search(struct Node *head, int key) {
    struct Node *temp = head;
    if (head == NULL) return 0;

    do {
        if (temp->data == key)
            return 1;
        temp = temp->next;
    } while (temp != head);

    return 0;
}

// Function to reverse the list
void reverse(struct Node **head) {
    if (*head == NULL) return;

    struct Node *prev = NULL, *current = *head, *next = NULL;
    struct Node *last = *head;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != *head);

    (*head)->next = prev;
    *head = prev;
}

// Function to display the list
void display(struct Node *head) {
    struct Node *temp = head;
    if (head == NULL) return;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    struct Node *head = NULL;

    // Insert elements
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    printf("Circular Linked List:\n");
    display(head);

    // Search for an element
    int key = 3;
    printf("Searching for %d: %s\n", key, search(head, key) ? "Found" : "Not Found");

    // Delete an element
    printf("Deleting 3 from the list:\n");
    deleteNode(&head, 3);
    display(head);

    // Reverse the list
    printf("Reversing the list:\n");
    reverse(&head);
    display(head);

    return 0;
}

