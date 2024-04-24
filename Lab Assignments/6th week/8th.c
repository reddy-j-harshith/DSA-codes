#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int value;   
    int array;   
    int index;   
} HeapNode;

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(HeapNode* heap, int size, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < size && heap[leftChild].value < heap[smallest].value)
        smallest = leftChild;

    if (rightChild < size && heap[rightChild].value < heap[smallest].value)
        smallest = rightChild;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

void buildMinHeap(HeapNode* heap, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        minHeapify(heap, size, i);
    }
}

void mergeArrays(int k, int** arrays, int* sizes) {
    HeapNode* heap = (HeapNode*)malloc(k * sizeof(HeapNode));

    for (int i = 0; i < k; i++) {
        heap[i].value = arrays[i][0];
        heap[i].array = i;
        heap[i].index = 0;
    }

    buildMinHeap(heap, k);

    int total_size = 0;
    for(int i = 0 ; i < k ; i++)
        total_size += sizes[i];

    int* result = (int*)malloc(sizeof(int) * (total_size));

    int resultIndex = 0;

    while (heap[0].value != INT_MAX) {
        result[resultIndex++] = heap[0].value;

        int nextIndex = heap[0].index + 1;

        if (nextIndex < sizes[heap[0].array]) {
            heap[0].value = arrays[heap[0].array][nextIndex];
            heap[0].index = nextIndex;
        } else {
            heap[0].value = INT_MAX;
        }

        minHeapify(heap, k, 0);
    }

    for (int i = 0; i < resultIndex; i++) {
        printf("%d ", result[i]);
    }

    free(heap);
    free(result);
}

void freeArrays(int k, int** arrays) {
    for (int i = 0; i < k; i++) {
        free(arrays[i]);
    }
    free(arrays);
}

int main() {
    int k;
    scanf("%d", &k);

    int** arrays = (int**)malloc(k * sizeof(int*));
    int* sizes = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++) {
        scanf("%d", &sizes[i]);
        arrays[i] = (int*)malloc(sizes[i] * sizeof(int));

        for (int j = 0; j < sizes[i]; j++) {
            scanf("%d", &arrays[i][j]);
        }
    }

    mergeArrays(k, arrays, sizes);

    freeArrays(k, arrays);
    free(sizes);

    return 0;
}
