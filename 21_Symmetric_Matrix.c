// WAP to implement Symmetric Matrix using a one-dimensional array.

#include <stdio.h>

#define MAX 100  // Maximum size of the matrix

// Function to get the index in the 1D array for element (i, j)
int getIndex(int i, int j) {
    if (i >= j) {
        return (i * (i + 1)) / 2 + j;
    }
    return -1;  // Invalid index for symmetric matrix
}

// Function to set a value in the symmetric matrix
void setValue(int arr[], int i, int j, int value) {
    int index = getIndex(i, j);
    if (index != -1) {
        arr[index] = value;
    }
}

// Function to get a value from the symmetric matrix
int getValue(int arr[], int i, int j) {
    int index = getIndex(i, j);
    if (index != -1) {
        return arr[index];
    }
    return -1;  // Return -1 if invalid
}

int main() {
    int n, i, j;
    int arr[MAX * (MAX + 1) / 2];  // Array to hold the symmetric matrix

    // Input the size of the matrix
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    // Input the elements of the symmetric matrix
    printf("Enter the elements of the symmetric matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            int value;
            printf("Element (%d, %d): ", i, j);
            scanf("%d", &value);
            setValue(arr, i, j, value);
        }
    }

    // Output the symmetric matrix
    printf("The symmetric matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", getValue(arr, i, j));
        }
        printf("\n");
    }

    return 0;
}
