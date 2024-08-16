/* WAP to display fibonacci series 
(i) using recursion, 
(ii) using iteration. */

#include <stdio.h>

// Function to return the nth Fibonacci number (Recursive)
int fibonacci_recursive(int n) {
    if (n <= 1)
        return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Function to display Fibonacci series using recursion
void display_fibonacci_recursive(int n) {
    printf("Fibonacci Series using Recursion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci_recursive(i));
    }
    printf("\n");
}

// Function to display Fibonacci series using iteration
void display_fibonacci_iterative(int n) {
    int a = 0, b = 1, next;

    printf("Fibonacci Series using Iteration: ");
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = a + b;
            a = b;
            b = next;
        }
        printf("%d ", next);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of terms for Fibonacci series: ");
    scanf("%d", &n);

    // Uncomment the desired method:
    
    // Display Fibonacci series using recursion
    // display_fibonacci_recursive(n);

    // Display Fibonacci series using iteration
    display_fibonacci_iterative(n);

    return 0;
}
