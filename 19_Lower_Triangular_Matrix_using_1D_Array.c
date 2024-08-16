// WAP to implement Lower Triangular Matrix using a one-dimensional array.

#include <stdio.h>

// Function to get the index of the 1D array for a given row and column
int getIndex(int row, int col) {
    return (row * (row + 1)) / 2 + col;
}

// Function to print the lower triangular matrix from the 1D array
void printLowerTriangularMatrix(int n, int arr[]) {
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", arr[index]);
            index++;
        }
        printf("\n");
    }
}

int main() {
    int n;

    // Input size of the matrix
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    int size = (n * (n + 1)) / 2; // Size of the 1D array
    int arr[size];

    // Input elements of the lower triangular matrix
    printf("Enter the elements of the lower triangular matrix:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the lower triangular matrix
    printf("The lower triangular matrix is:\n");
    printLowerTriangularMatrix(n, arr);

    return 0;
}
