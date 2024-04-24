#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(int *heap, int n, int i){
    int smallest = i;
    int left = 2 * i + 1, right = 2 * i + 2;
    if(left < n && heap[left] < heap[smallest])
        smallest = left;
    if(right < n && heap[right] < heap[smallest])
        smallest = right;
    if(i != smallest){
        swap(&heap[smallest], &heap[i]);
        min_heapify(heap, n, smallest);
    }
}


void build_heap(int *heap, int n){
    for(int i = n / 2 - 1; i >= 0; i--)
        min_heapify(heap, n, i);
}


int minimum(char *arr, int n, int k){

    int unique = 1;
    for(int i = 1; i < n; i++)
        if(arr[i - 1] != arr[i]) unique++;

    int *heap = (int *)malloc(sizeof(int) * unique);

    heap[0] = 1;
    int idx = 1;

    for(int i = 1; i < n; i++){
        if(arr[i - 1] != arr[i]){
            heap[idx] = 1;
        } else {
            idx--;
            heap[idx]++;
        }
            idx++;
    }

    build_heap(heap, unique);

    int res = 0;
    idx = 0;
    while(k > 0){
        int temp = 0;
        while(k > 0 && heap[idx] > 0){
            temp++;
            heap[idx]--;k--;
        }
        res += pow(temp, 2);
        unique--;
        idx++;
    }
    return res;
}


int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    char arr[n];
    for(int i = 0; i < n; i++ )
        scanf(" %c", &arr[i]);

    int result = minimum(arr, n, k);
    printf("%d ", result);
}