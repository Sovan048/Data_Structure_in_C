// WAP to implement Diagonal Matrix using a one-dimensional array.

#include <stdio.h>

#define SIZE 4 // Define the size of the diagonal matrix

void printDiagonalMatrix(int diagArray[], int size) {
    // Construct and print the diagonal matrix
    printf("Diagonal Matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                printf("%d ", diagArray[i]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    int diagArray[SIZE];
    
    // Input the diagonal elements
    printf("Enter the %d diagonal elements:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &diagArray[i]);
    }
    
    // Print the diagonal matrix
    printDiagonalMatrix(diagArray, SIZE);
    
    return 0;
}
