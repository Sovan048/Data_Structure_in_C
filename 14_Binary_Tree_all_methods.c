/* WAP to create a Binary Search Tree and include following operations in tree:
(a) Insertion (Recursive and Iterative Implementation)
(b) Deletion by copying
(c) Deletion by Merging
(d) Search a number in BST
(e) Display its preorder, postorder and in-order traversals recursively
(f) Display its preorder, postorder and in-order traversals iteratively
(g) Display its level-by-level traversals
(h) Count the non-leaf nodes and leaf nodes
(i) Display height of tree
(j) Create a mirror image of tree
(k) Check whether two BSTs are equal or not */

#include <stdio.h>
#include <stdlib.h>

// Definition of a TreeNode
typedef struct TreeNode {
    int key;
    struct TreeNode *left, *right;
} TreeNode;

// Function to create a new TreeNode
TreeNode* createNode(int key) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// (a) Insertion (Recursive)
TreeNode* insertRecursive(TreeNode* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insertRecursive(root->left, key);
    } else {
        root->right = insertRecursive(root->right, key);
    }
    return root;
}

// (a) Insertion (Iterative)
TreeNode* insertIterative(TreeNode* root, int key) {
    TreeNode* newNode = createNode(key);
    if (root == NULL) {
        return newNode;
    }
    TreeNode* parent = NULL;
    TreeNode* current = root;
    while (current != NULL) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    if (key < parent->key) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
    return root;
}

// (b) Deletion by copying
TreeNode* findMin(TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

TreeNode* deleteCopy(TreeNode* root, int key) {
    if (root == NULL) return root;
    if (key < root->key) {
        root->left = deleteCopy(root->left, key);
    } else if (key > root->key) {
        root->right = deleteCopy(root->right, key);
    } else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        TreeNode* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteCopy(root->right, temp->key);
    }
    return root;
}

// (c) Deletion by merging
TreeNode* deleteMerge(TreeNode* root, int key) {
    if (root == NULL) return root;
    if (key < root->key) {
        root->left = deleteMerge(root->left, key);
    } else if (key > root->key) {
        root->right = deleteMerge(root->right, key);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        TreeNode* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteMerge(root->right, temp->key);
    }
    return root;
}

// (d) Search a number in BST
TreeNode* search(TreeNode* root, int key) {
    if (root == NULL || root->key == key) return root;
    if (key < root->key) return search(root->left, key);
    return search(root->right, key);
}

// (e) Display traversals recursively
void inorderRecursive(TreeNode* root) {
    if (root != NULL) {
        inorderRecursive(root->left);
        printf("%d ", root->key);
        inorderRecursive(root->right);
    }
}

void preorderRecursive(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
}

void postorderRecursive(TreeNode* root) {
    if (root != NULL) {
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        printf("%d ", root->key);
    }
}

// (f) Display traversals iteratively
void inorderIterative(TreeNode* root) {
    TreeNode* stack[100];
    int top = -1;
    TreeNode* current = root;

    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->key);
        current = current->right;
    }
}

void preorderIterative(TreeNode* root) {
    if (root == NULL) return;
    TreeNode* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top >= 0) {
        TreeNode* node = stack[top--];
        printf("%d ", node->key);
        if (node->right != NULL) stack[++top] = node->right;
        if (node->left != NULL) stack[++top] = node->left;
    }
}

void postorderIterative(TreeNode* root) {
    if (root == NULL) return;
    TreeNode* stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;

    while (top1 >= 0) {
        TreeNode* node = stack1[top1--];
        stack2[++top2] = node;
        if (node->left != NULL) stack1[++top1] = node->left;
        if (node->right != NULL) stack1[++top1] = node->right;
    }

    while (top2 >= 0) {
        printf("%d ", stack2[top2--]->key);
    }
}

// (g) Display level-by-level traversals
void levelOrder(TreeNode* root) {
    if (root == NULL) return;
    TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        TreeNode* node = queue[front++];
        printf("%d ", node->key);
        if (node->left != NULL) queue[rear++] = node->left;
        if (node->right != NULL) queue[rear++] = node->right;
    }
}

// (h) Count non-leaf and leaf nodes
void countNodes(TreeNode* root, int* leafCount, int* nonLeafCount) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        (*leafCount)++;
    } else {
        (*nonLeafCount)++;
        countNodes(root->left, leafCount, nonLeafCount);
        countNodes(root->right, leafCount, nonLeafCount);
    }
}

// (i) Display height of tree
int height(TreeNode* root) {
    if (root == NULL) return -1;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// (j) Create a mirror image of tree
TreeNode* mirror(TreeNode* root) {
    if (root == NULL) return NULL;
    TreeNode* newRoot = createNode(root->key);
    newRoot->left = mirror(root->right);
    newRoot->right = mirror(root->left);
    return newRoot;
}

// (k) Check whether two BSTs are equal or not
int areEqual(TreeNode* root1, TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) return 1;
    if (root1 == NULL || root2 == NULL) return 0;
    return (root1->key == root2->key &&
            areEqual(root1->left, root2->left) &&
            areEqual(root1->right, root2->right));
}

// Utility function to print a newline
void printNewLine() {
    printf("\n");
}

// Main function to demonstrate BST operations
int main() {
    TreeNode* root = NULL;

    // Insertion
    root = insertRecursive(root, 50);
    root = insertRecursive(root, 30);
    root = insertRecursive(root, 70);
    root = insertRecursive(root, 20);
    root = insertRecursive(root, 40);
    root = insertRecursive(root, 60);
    root = insertRecursive(root, 80);

    // Display traversals
    printf("Inorder Traversal (Recursive): ");
    inorderRecursive(root);
    printNewLine();

    printf("Preorder Traversal (Recursive): ");
    preorderRecursive(root);
    printNewLine();

    printf("Postorder Traversal (Recursive): ");
    postorderRecursive(root);
    printNewLine();

    printf("Inorder Traversal (Iterative): ");
    inorderIterative(root);
    printNewLine();

    printf("Preorder Traversal (Iterative): ");
    preorderIterative(root);
    printNewLine();

    printf("Postorder Traversal (Iterative): ");
    postorderIterative(root);
    printNewLine();

    printf("Level Order Traversal: ");
    levelOrder(root);
    printNewLine();

    int leafCount = 0, nonLeafCount = 0;
    countNodes(root, &leafCount, &nonLeafCount);
    printf("Leaf Nodes Count: %d\n", leafCount);
    printf("Non-Leaf Nodes Count: %d\n", nonLeafCount);

    printf("Height of Tree: %d\n", height(root));

    TreeNode* mirroredRoot = mirror(root);
    printf("Mirror Image Inorder Traversal: ");
    inorderRecursive(mirroredRoot);
    printNewLine();

    // Checking equality
    printf("Trees are %sequal\n", areEqual(root, mirroredRoot) ? "" : "not ");

    // Deletion
    root = deleteCopy(root, 20);
    printf("Inorder Traversal after deleting 20: ");
    inorderRecursive(root);
    printNewLine();

    // Free memory (Not shown here for brevity)

    return 0;
}
