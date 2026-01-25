#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high, int pivotChoice) {
    int pivotIndex;
    if (pivotChoice == 1) {
        pivotIndex = low;
    } else if (pivotChoice == 2) {
        pivotIndex = high;
    } else {
        pivotIndex = low + rand() % (high - low + 1);
        printf("Random Pivot Element Chosen: %d\n", arr[pivotIndex]);
    }
    swap(&arr[pivotIndex], &arr[high]);
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high, int pivotChoice) {
    if (low < high) {
        int pi = partition(arr, low, high, pivotChoice);
        quickSort(arr, low, pi - 1, pivotChoice);
        quickSort(arr, pi + 1, high, pivotChoice);
    }
}
int main() {
    printf("CH.SC.U4CSE24113\n");
    int n, pivotChoice;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return 1;
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Choose Pivot Element:\n1. First Element\n2. Last Element\n3. Random Element\nChoice: ");
    scanf("%d", &pivotChoice);
    quickSort(arr, 0, n - 1, pivotChoice);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}