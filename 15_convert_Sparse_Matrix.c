// WAP to convert the Sparse Matrix into non-zero form and vice-versa.

#include <stdio.h>

#define MAX 100

void sparseToTriplet(int sparse[MAX][MAX], int rows, int cols, int triplet[MAX * MAX][3], int *k) {
    *k = 0;  // Initialize count of triplets

    // Traverse the sparse matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (sparse[i][j] != 0) {
                // Store non-zero elements in triplet form
                triplet[*k][0] = i;    // Row index
                triplet[*k][1] = j;    // Column index
                triplet[*k][2] = sparse[i][j]; // Value
                (*k)++;
            }
        }
    }
}

void tripletToSparse(int triplet[MAX * MAX][3], int k, int rows, int cols, int sparse[MAX][MAX]) {
    // Initialize sparse matrix with zeros
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sparse[i][j] = 0;
        }
    }

    // Reconstruct sparse matrix from triplet form
    for (int i = 0; i < k; i++) {
        int row = triplet[i][0];
        int col = triplet[i][1];
        int value = triplet[i][2];
        sparse[row][col] = value;
    }
}

int main() {
    int choice;
    int rows, cols, k;
    int sparse[MAX][MAX];
    int triplet[MAX * MAX][3];

    printf("Choose an option:\n");
    printf("1. Convert Sparse Matrix to Triplet Form\n");
    printf("2. Convert Triplet Form to Sparse Matrix\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            printf("Enter the number of rows and columns: ");
            scanf("%d %d", &rows, &cols);

            printf("Enter the elements of the sparse matrix:\n");
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    scanf("%d", &sparse[i][j]);
                }
            }

            // Convert sparse matrix to triplet form
            sparseToTriplet(sparse, rows, cols, triplet, &k);

            // Print triplet form
            printf("Triplet form:\n");
            printf("Row Column Value\n");
            for (int i = 0; i < k; i++) {
                printf("%d %d %d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
            }
            break;
        }
        case 2: {
            printf("Enter the number of rows and columns: ");
            scanf("%d %d", &rows, &cols);

            printf("Enter the number of non-zero elements: ");
            scanf("%d", &k);

            printf("Enter the triplet form (row column value):\n");
            for (int i = 0; i < k; i++) {
                scanf("%d %d %d", &triplet[i][0], &triplet[i][1], &triplet[i][2]);
            }

            // Convert triplet form to sparse matrix
            tripletToSparse(triplet, k, rows, cols, sparse);

            // Print the sparse matrix
            printf("Sparse matrix:\n");
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    printf("%d ", sparse[i][j]);
                }
                printf("\n");
            }
            break;
        }
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
