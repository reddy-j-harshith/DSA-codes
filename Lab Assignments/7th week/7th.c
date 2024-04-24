#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

typedef struct{
    int index;
    int dif;
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
    if(left < n){
        if(left < n && heap[smallest].dif > heap[left].dif)
            smallest = left;
        else if(left < n && heap[smallest].dif == heap[left].dif){
            if(heap[smallest].value > heap[left].value) smallest = left;
        }
    }
    if(right < n){
        if(heap[smallest].dif > heap[right].dif)
            smallest = right;
        else if(heap[smallest].dif == heap[right].dif)
            if(heap[smallest].value > heap[right].value) smallest = right;
    }
    if(i != smallest){
        swap(&heap[i], &heap[smallest]);
        min_heapify(heap, n, smallest);
    }    
}


void build_heap(HeapNode *heap, int n){
    for(int i = n / 2 - 1; i >= 0; i--)
        min_heapify(heap, n, i);
}


void print_and_extract(HeapNode *heap, int n){
    printf("%d ", heap[0].value);
    swap(&heap[0], &heap[n - 1]);
    min_heapify(heap, n - 1, 0);
}


void k_closest(int *arr, int n, int x, int k){

    HeapNode *heap = (HeapNode *)malloc(sizeof(HeapNode) * n);

    for(int i = 0 ; i < n; i++){
        heap[i].value = arr[i];
        heap[i].index = i;
        heap[i].dif = abs(arr[i] - x);
    }

    build_heap(heap, n);

    printf("\n");
    for(int i = 1; i <= k; i++){
        print_and_extract(heap, n--);

    }
    free(heap);
}


int main(){
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);
    int arr[n];
    for(int i = 0; i < n ; i++)
        scanf("%d", &arr[i]);

    k_closest(arr, n, x, k);
}