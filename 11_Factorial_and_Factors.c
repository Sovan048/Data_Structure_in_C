/* WAP to calculate factorial and to compute the factors of a given number 
(i) using recursion, 
(ii) using iteration. */

#include <stdio.h>

// Function prototypes
int factorial_recursive(int n);
int factorial_iterative(int n);
void factors_recursive(int n, int i);
void factors_iterative(int n);

int main() {
    int num;

    // Input the number for which factorial and factors are to be calculated
    printf("Enter a number: ");
    scanf("%d", &num);

    // Factorial calculations
    printf("Factorial (Recursive): %d\n", factorial_recursive(num));
    printf("Factorial (Iterative): %d\n", factorial_iterative(num));

    // Factors calculations
    printf("Factors (Recursive): ");
    factors_recursive(num, 1);
    printf("\n");

    printf("Factors (Iterative): ");
    factors_iterative(num);
    printf("\n");

    return 0;
}

// Factorial using recursion
int factorial_recursive(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial_recursive(n - 1);
}

// Factorial using iteration
int factorial_iterative(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Factors using recursion
void factors_recursive(int n, int i) {
    if (i > n / 2) {
        if (n % i == 0) {
            printf("%d ", i);
        }
        return;
    }
    if (n % i == 0) {
        printf("%d ", i);
    }
    factors_recursive(n, i + 1);
}

// Factors using iteration
void factors_iterative(int n) {
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            printf("%d ", i);
        }
    }
    // Include the number itself as a factor
    printf("%d ", n);
}
