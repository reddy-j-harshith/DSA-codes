#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int temp[right - left + 1];  // Temporary array for merging

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements from left subarray
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from right subarray
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy merged elements back to original array
    for (i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }
}

void mergeSort(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    free(arr);  // Free allocated memory
    return 0;
}
