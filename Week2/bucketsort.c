#include <stdio.h>
#include <stdlib.h>

// Bucket sort implemented as counting buckets (for non-negative integers)
void bucketSort(int arr[], int n) {
    if (n <= 0) return;

    int i;
    int max = arr[0];

    // Find maximum element
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // Create buckets (0..max)
    int *bucket = (int *)calloc(max + 1, sizeof(int));
    if (bucket == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Fill buckets: count occurrences
    for (i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }

    // Write back to original array in sorted order
    int index = 0;
    for (i = 0; i <= max; i++) {
        while (bucket[i] > 0) {
            arr[index++] = i;
            bucket[i]--;
        }
    }

    free(bucket);
}