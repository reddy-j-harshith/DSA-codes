#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int index;
    int value;
} HeapNode;

void swap(HeapNode *a, HeapNode *b){
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(HeapNode *heap, int n, int i){
    int smallest = i;
    int left = 2 * i + 1, right = 2 * i + 2;
    if(left < n && heap[smallest].value > heap[left].value)
        smallest = left;
    if(right < n && heap[smallest].value > heap[right].value )
        smallest = right;
    if(i != smallest){
        swap(&heap[smallest], &heap[i]);
        min_heapify(heap, n, smallest);
    }
}

void build_heap(HeapNode *heap, int n){
    for(int i = n / 2 - 1; i >= 0; i--)
        min_heapify(heap, n, i);
}

void print_indices(int *arr, int n, int x){

    HeapNode *heap = (HeapNode *)malloc(sizeof(HeapNode) * n);

    for(int i = 0; i < n; i++){
        heap[i].index = i;
        heap[i].value = arr[i];
    }

    build_heap(heap, n);

    int count = 0;

    int size = n;
    while(heap[0].value < x){
        printf("%d ", heap[0].index + 1);
        swap(&heap[0], &heap[n - 1]);
        n--; count++;
        min_heapify(heap, n, 0);
    }

}

int main(){
    int n, x;
    scanf("%d %d", &n, &x);
    int *arr = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n ; i++)
        scanf("%d", &arr[i]);

    print_indices(arr, n, x);
}