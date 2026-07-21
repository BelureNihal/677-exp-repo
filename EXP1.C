#include <stdio.h>

int search(int arr[], int size, int target) 
{
    int low = 0;
    int high = size - 1;
    int result_index = -1; 

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            result_index = mid; 
            high = mid - 1;     
        } 
        else if (arr[mid] > target) {
            high = mid - 1;
        } 
        else {
            low = mid + 1;
        }
    }
    return result_index; 
}

int count(int arr[], int size, int target) 
{
    int occurrences = 0; 
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            occurrences++;
        }
    }
    return occurrences;
}

int main(void) 
{
    int size;
    int occurrence;
    int total_count;
    int target;

    printf("Enter the size of an array: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    // Use a Variable Length Array (VLA) after size is validated
    int arr[size]; 

    printf("Enter the elements of an array (in sorted order):\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element of the same array: ");
    scanf("%d", &target);

    occurrence = search(arr, size, target);
    
    if (occurrence != -1) {
        printf("1st occurrence of %d is at index %d\n", target, occurrence);
    } else {
        printf("The element %d does not exist in the array.\n", target);
    }

    total_count = count(arr, size, target);
    printf("The target %d occurred %d times in the whole array.\n", target, total_count);

    return 0;
}

