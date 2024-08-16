/* WAP to calculate GCD of 2 number 
(i) with recursion 
(ii) without recursion */

#include <stdio.h>

// Function to compute GCD using recursion
int gcd_recursive(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd_recursive(b, a % b);
}

// Function to compute GCD using iteration
int gcd_iterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2, choice;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("Choose method to calculate GCD:\n");
    printf("1. Recursive\n");
    printf("2. Iterative\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("GCD of %d and %d using recursion is %d\n", num1, num2, gcd_recursive(num1, num2));
            break;
        case 2:
            printf("GCD of %d and %d using iteration is %d\n", num1, num2, gcd_iterative(num1, num2));
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
