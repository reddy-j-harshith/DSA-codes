#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Max Heapify function
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Min Heapify function
void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Function to insert an element into max heap
void insertMaxHeap(int maxHeap[], int* maxHeapSize, int num) {
    (*maxHeapSize)++;
    int i = *maxHeapSize - 1;
    maxHeap[i] = num;

    while (i != 0 && maxHeap[(i - 1) / 2] < maxHeap[i]) {
        swap(&maxHeap[i], &maxHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to insert an element into min heap
void insertMinHeap(int minHeap[], int* minHeapSize, int num) {
    (*minHeapSize)++;
    int i = *minHeapSize - 1;
    minHeap[i] = num;

    while (i != 0 && minHeap[(i - 1) / 2] > minHeap[i]) {
        swap(&minHeap[i], &minHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to find median
void findMedian(int maxHeap[], int minHeap[], int* maxHeapSize, int* minHeapSize) {
    if (*maxHeapSize == *minHeapSize) {
        printf("%d\n", (maxHeap[0] + minHeap[0]) / 2);
    } else if (*maxHeapSize > *minHeapSize) {
        printf("%d\n", maxHeap[0]);
    } else {
        printf("%d\n", minHeap[0]);
    }
}

int main() {
    int q;
    scanf("%d", &q);

    int maxHeap[q];
    int minHeap[q];
    int maxHeapSize = 0;
    int minHeapSize = 0;

    for (int i = 0; i < q; i++) {
        int type, num;
        scanf("%d", &type);

        if (type == 1) {
            scanf("%d", &num);
            if (maxHeapSize == 0 || num < maxHeap[0])
                insertMaxHeap(maxHeap, &maxHeapSize, num);
            else
                insertMinHeap(minHeap, &minHeapSize, num);

            // Balance the heaps
            if (maxHeapSize > minHeapSize + 1) {
                insertMinHeap(minHeap, &minHeapSize, maxHeap[0]);
                maxHeap[0] = maxHeap[maxHeapSize - 1];
                maxHeapSize--;
                maxHeapify(maxHeap, maxHeapSize, 0);
            } else if (minHeapSize > maxHeapSize) {
                insertMaxHeap(maxHeap, &maxHeapSize, minHeap[0]);
                minHeap[0] = minHeap[minHeapSize - 1];
                minHeapSize--;
                minHeapify(minHeap, minHeapSize, 0);
            }
        } else if (type == 2) {
            findMedian(maxHeap, minHeap, &maxHeapSize, &minHeapSize);
        }
    }

    return 0;
}
