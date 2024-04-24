#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100000

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(int *arr, int n, int i){
    int largest = i;
    int left = 2 * i + 1, right = 2 * i + 2;
    if(left < n && arr[left] > arr[largest])
        largest = left;
    if(right < n && arr[right] > arr[largest])
        largest = right;
    if(i != largest){
        swap(&arr[i], &arr[largest]);
        max_heapify(arr, n, largest);
    }
}

void build_heap(int *arr, int n){
    for(int i = n / 2 - 1; i >= 0; i--)
        max_heapify(arr, n, i);
}


int optimal(int arr[MAX_SIZE][2], int n, int k){

    int *sum = (int *)malloc(n * sizeof(int));

    for(int i = 0; i < n ; i++)
        sum[i] = arr[i][0] + arr[i][1];

    build_heap(sum, n);

    int res = 0;

    while(k > 0){
        if(sum[0] >= 0){
            res += sum[0];
        }        
        swap(&sum[0], &sum[n - 1]);
        n--;
        max_heapify(sum, n, 0);
        k--;
    }
    return res;
}


int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[MAX_SIZE][2];
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &arr[i][0]);
    
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i][1]);

    int result = optimal(arr, n, k);
    printf("%d\n", result);
}