/* WAP to create a Threaded Binary Tree as per in-order traversal, and implement operations like finding the successor / predecessor of an element, insert an element, and in-order traversal */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a threaded binary tree node
typedef struct ThreadedNode {
    int data;
    struct ThreadedNode* left;
    struct ThreadedNode* right;
    int lthread;
    int rthread;
} ThreadedNode;

// Create a new threaded binary tree node
ThreadedNode* createNode(int data) {
    ThreadedNode* newNode = (ThreadedNode*)malloc(sizeof(ThreadedNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->lthread = 1;  // Initially, the left pointer is a thread
    newNode->rthread = 1;  // Initially, the right pointer is a thread
    return newNode;
}

// In-order traversal of the threaded binary tree
void inOrderTraversal(ThreadedNode* root) {
    ThreadedNode* current = root;

    // Go to the leftmost node
    while (current != NULL && current->lthread == 0) {
        current = current->left;
    }

    while (current != NULL) {
        printf("%d ", current->data);
        // If the right pointer is a thread, go to the successor
        if (current->rthread == 1) {
            current = current->right;
        } else {
            // Go to the leftmost node in the right subtree
            current = current->right;
            while (current != NULL && current->lthread == 0) {
                current = current->left;
            }
        }
    }
}

// Find the successor of a node
ThreadedNode* findSuccessor(ThreadedNode* node) {
    if (node->rthread == 1) {
        return node->right;
    } else {
        ThreadedNode* temp = node->right;
        while (temp != NULL && temp->lthread == 0) {
            temp = temp->left;
        }
        return temp;
    }
}

// Find the predecessor of a node
ThreadedNode* findPredecessor(ThreadedNode* node) {
    if (node->lthread == 1) {
        return node->left;
    } else {
        ThreadedNode* temp = node->left;
        while (temp != NULL && temp->rthread == 0) {
            temp = temp->right;
        }
        return temp;
    }
}

// Insert a new node into the threaded binary tree
ThreadedNode* insertNode(ThreadedNode* root, int data) {
    ThreadedNode* newNode = createNode(data);

    if (root == NULL) {
        return newNode;
    }

    ThreadedNode* parent = NULL;
    ThreadedNode* current = root;
    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            if (current->lthread == 0) {
                current = current->left;
            } else {
                break;
            }
        } else {
            if (current->rthread == 0) {
                current = current->right;
            } else {
                break;
            }
        }
    }

    if (data < parent->data) {
        newNode->left = parent->left;
        newNode->right = parent;
        parent->lthread = 0;
        parent->left = newNode;
    } else {
        newNode->right = parent->right;
        newNode->left = parent;
        parent->rthread = 0;
        parent->right = newNode;
    }

    return root;
}

// Utility function to create a threaded binary tree from a sorted array
ThreadedNode* sortedArrayToThreadedTree(int arr[], int start, int end) {
    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    ThreadedNode* root = createNode(arr[mid]);

    root->left = sortedArrayToThreadedTree(arr, start, mid - 1);
    root->right = sortedArrayToThreadedTree(arr, mid + 1, end);

    if (root->left != NULL) {
        root->lthread = 0;
    }

    if (root->right != NULL) {
        root->rthread = 0;
    }

    return root;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create a threaded binary tree from a sorted array
    ThreadedNode* root = sortedArrayToThreadedTree(arr, 0, n - 1);

    // Perform in-order traversal
    printf("In-order Traversal:\n");
    inOrderTraversal(root);
    printf("\n");

    // Find and print successor and predecessor of a node
    ThreadedNode* node = root->left->right; // For example, node with value 3
    printf("Node: %d\n", node->data);
    ThreadedNode* successor = findSuccessor(node);
    ThreadedNode* predecessor = findPredecessor(node);
    if (successor != NULL) {
        printf("Successor: %d\n", successor->data);
    } else {
        printf("No Successor\n");
    }
    if (predecessor != NULL) {
        printf("Predecessor: %d\n", predecessor->data);
    } else {
        printf("No Predecessor\n");
    }

    return 0;
}
