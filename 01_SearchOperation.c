// Write a program to search an element from a list. Give users the option to perform Linear or Binary search.

#include <stdio.h>

// Function prototypes
int linearSearch(int arr[], int n, int key);
int binarySearch(int arr[], int n, int key);
void sortArray(int arr[], int n);
void performSearch(int (*searchFunc)(int[], int, int), int arr[], int n, int key);

int main() {
    int choice, key, n, i;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the element to search: ");
    scanf("%d", &key);
    
    printf("Choose search method:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            performSearch(linearSearch, arr, n, key);
            break;
        case 2:
            sortArray(arr, n); // Binary search requires sorted array
            performSearch(binarySearch, arr, n, key);
            break;
        default:
            printf("Invalid choice.\n");
    }
    
    return 0;
}

// Function to perform linear search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// Function to perform binary search
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Function to sort the array (for binary search)
void sortArray(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to perform search using a function pointer
void performSearch(int (*searchFunc)(int[], int, int), int arr[], int n, int key) {
    int result = searchFunc(arr, n, key);
    
    if (result != -1) {
        printf("Element found at index %d.\n", result);
    } else {
        printf("Element not found.\n");
    }
}