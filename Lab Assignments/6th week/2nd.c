#include<stdio.h>
#include<stdbool.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high){
    int pivot = arr[low];
    int  i = low - 1, j = high + 1;
    while(true){
        do{
            i++;
        }while(arr[i] < pivot);
        do{
            j--;
        }while(arr[j] > pivot);
        if(i >= j) return j;
        swap(&arr[i], &arr[j]);
    }
}

void quick_sort(int *arr, int low, int high){
    if(low < high){
        int location = partition(arr, low, high);
        quick_sort(arr, low, location);
        quick_sort(arr, location + 1, high);
    }
}

int main(){

    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n;i++)
        scanf("%d", &arr[i]);

    quick_sort(arr, 0, n - 1);

    for(int i = 0; i< n; i++)
        printf("%d ", arr[i]);
}