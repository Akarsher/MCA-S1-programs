#include <stdio.h>
void displayArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Current Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int insertElement(int arr[], int size) {
    int index, element;
    printf("Enter the index to insert the element (0 to %d): ", size);
    scanf("%d", &index);
    if (index < 0 || index > size) {
        printf("Invalid index.\n");
        return size;  
    }
    printf("Enter the element to insert: ");
    scanf("%d", &element);
    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
    size++;
    printf("Element '%d' inserted at index %d.\n", element, index);
    return size; 
}

int deleteElement(int arr[], int size) {
    int index;
    if (size == 0) {
        printf("Array is empty. Cannot delete element.\n");
        return size;  
    }
    printf("Enter the index to delete the element (0 to %d): ", size - 1);
    scanf("%d", &index);
    if (index < 0 || index >= size) {
        printf("Invalid index.\n");
        return size; 
    }
    int removedElement = arr[index];
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("Element '%d' deleted from index %d.\n", removedElement, index);
    return size;  
}
int main() {
    int arr[100];
    int size, i;
    int choice;

    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the array elements:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Traverse Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                size = insertElement(arr, size);
                break;
            case 2:
                size = deleteElement(arr, size);
                break;
            case 3:
                displayArray(arr, size);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}
