#include <stdio.h>

void minHeapify(int arr[], int n, int i) {
    int smallest = i;         // Initialize smallest as root
    int left = 2 * i + 1;     // left child
    int right = 2 * i + 2;    // right child
    int temp;

    // If left child is smaller than root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // If right child is smaller than smallest so far
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If smallest is not root
    if (smallest != i) {
        temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;

        // Recursively heapify the affected sub-tree
        minHeapify(arr, n, smallest);
    }
}

void heapSortMin(int arr[], int n) {
    int i, temp;

    // Build min heap
    for (i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    // One by one extract elements from heap
    for (i = n - 1; i > 0; i--) {
        // Move current root (smallest) to end
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call minHeapify on the reduced heap
        minHeapify(arr, i, 0);
    }
}