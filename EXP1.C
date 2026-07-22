#include <stdio.h>

int First_ccurrence(int arr[], int size, int target) {
    int i; 
    for (i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}

int count(int arr[], int size, int target) {
    int counter = 0; 
    int i; 
    for (i = 0; i < size; i++) {
        if (arr[i] == target) {
            counter++;
        }
    }
    return counter; 
}

int main() {
    int size, target;
    int firstPosition;
    int T_Count;
    int i; 

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements you want in the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target number to search: ");
    scanf("%d", &target);

    firstPosition = First_ccurrence(arr, size, target);
    T_Count = count(arr, size, target);

    if (firstPosition != -1) {
        printf("\nNumber of occurrences of %d: %d\n", target, T_Count);
        printf("First occurrence position (Index): %d \n", firstPosition );
    } else {
        printf("\nElement %d was not found in the array.\n", target);
    }

    return 0;
}
