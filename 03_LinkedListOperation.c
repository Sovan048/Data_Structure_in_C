// Implement Linked List. Include functions for insertion, deletion and search of a number, reverse the list and concatenate two linked lists

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end
void insert(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

// Function to delete a node with a given key
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// Function to search for a node
int search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key)
            return 1;
        current = current->next;
    }
    return 0;
}

// Function to reverse the linked list
void reverse(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

// Function to concatenate two linked lists
void concatenate(struct Node** head_ref1, struct Node** head_ref2) {
    if (*head_ref1 == NULL) {
        *head_ref1 = *head_ref2;
        return;
    }

    struct Node* temp = *head_ref1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = *head_ref2;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function to test the linked list
int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // Insertion in list 1
    insert(&head1, 1);
    insert(&head1, 2);
    insert(&head1, 3);

    // Insertion in list 2
    insert(&head2, 4);
    insert(&head2, 5);

    printf("Linked list 1: ");
    printList(head1);

    printf("Linked list 2: ");
    printList(head2);

    // Search for a number in list 1
    int num = 2;
    if (search(head1, num))
        printf("Number %d found in list 1\n", num);
    else
        printf("Number %d not found in list 1\n", num);

    // Delete a node from list 1
    deleteNode(&head1, 2);
    printf("Linked list 1 after deletion: ");
    printList(head1);

    // Reverse list 1
    reverse(&head1);
    printf("Reversed linked list 1: ");
    printList(head1);

    // Concatenate list 1 and list 2
    concatenate(&head1, &head2);
    printf("Concatenated linked list: ");
    printList(head1);

    return 0;
}
