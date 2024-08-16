/*Implement Doubly Linked List. Include functions for insertion, deletion and search of a number, reverse the list.*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for Doubly Linked List
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to delete a node with a given value
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;

    // If the list is empty
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // If the node to be deleted is the head node
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    // If the key is not present in the list
    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    // If the node to be deleted is not the head
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}

// Function to search for a node in the list
struct Node* searchNode(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to reverse the doubly linked list
void reverseList(struct Node** head) {
    struct Node* temp = NULL;
    struct Node* current = *head;

    // Swap next and prev for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Before changing the head, check for the cases like empty list and list with only one node
    if (temp != NULL) {
        *head = temp->prev;
    }
}

// Function to print the list
void printList(struct Node* node) {
    struct Node* last;
    printf("Traversal in forward direction:\n");
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtBeginning(&head, 5);

    printf("Original List:\n");
    printList(head);

    deleteNode(&head, 20);
    printf("After deleting 20:\n");
    printList(head);

    struct Node* searchResult = searchNode(head, 30);
    if (searchResult != NULL) {
        printf("Node with value 30 found.\n");
    } else {
        printf("Node with value 30 not found.\n");
    }

    reverseList(&head);
    printf("Reversed List:\n");
    printList(head);

    return 0;
}
