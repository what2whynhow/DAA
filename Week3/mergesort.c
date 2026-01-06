#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int *temp = (int *)malloc((right - left + 1) * sizeof(int));
    
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    
    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
    
    free(temp);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    mergeSort(arr, 0, n - 1);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}