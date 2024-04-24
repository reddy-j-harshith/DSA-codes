#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(int *arr, int n, int i){
    int smallest = i;
    int left = 2 * i + 1, right = 2 * i + 2;
    if(left < n && arr[left] < arr[smallest])
        smallest = left;
    if(right < n && arr[right] < arr[smallest])
        smallest = right;
    if(i != smallest){
        swap(&arr[smallest], &arr[i]);
        min_heapify(arr, n, smallest);
    }
}

void build_heap(int *arr, int n){
    for(int i = (n) / 2; i >= 0; i--)
        min_heapify(arr, i, 0);
}

void k_smallest(int *arr, int n, int k){
    build_heap(arr, k);
    for(int i = k + 1; i < n; i++){
        if(arr[0] > arr[i]){
            arr[0] = arr[i];
            min_heapify(arr, k, 0);
            printf("%d ", arr[0]);
        }
    }
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int *arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n ; i++)
        scanf("%d", &arr[i]);

    k_smallest(arr, n, k);
}