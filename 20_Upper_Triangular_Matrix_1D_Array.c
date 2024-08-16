// WAP to implement the Upper Triangular Matrix using a one-dimensional array.

#include <stdio.h>

#define MAX 100

// Function to convert 2D indices to 1D index
int getIndex(int row, int col, int n) {
    if (row > col) return -1; // Invalid index for upper triangular matrix
    return (row * n) - (row * (row + 1) / 2) + col;
}

// Function to print the upper triangular matrix from 1D array
void printUpperTriangular(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j)
                printf("%d ", arr[getIndex(i, j, n)]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("Size too large!\n");
        return 1;
    }

    int arr[(n * (n + 1)) / 2];
    
    // Input upper triangular matrix elements
    printf("Enter the elements of the upper triangular matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int index = getIndex(i, j, n);
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr[index]);
        }
    }
    
    // Print the matrix
    printf("The upper triangular matrix is:\n");
    printUpperTriangular(arr, n);
    
    return 0;
}
