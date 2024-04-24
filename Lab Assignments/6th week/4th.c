#include<stdio.h>


void insertion_sort(int *arr, int low, int high){
    for(int i = low; i < high + 1; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= low && key < arr[j]){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}



void merge(int *arr, int low, int mid, int high){
    int n1 = mid - low + 1, n2 = high - mid;
    int left[n1], right[n2];
    for(int i = 0; i < n1; i++) { left[i] = arr[low + i]; }
    for(int i = 0; i < n2; i++) { right[i] = arr[mid + i + 1]; }

    int i = 0, j = 0, k = low;
    while(i < n1 && j < n2){    
        if(left[i] <= right[j]) { arr[k++] = left[i++]; }
        else                    { arr[k++] = right[j++]; }
    }

    while(i < n1) { arr[k++] = left[i++]; }
    while(j < n2) { arr[k++] = right[j++]; }
}


void merge_sort(int *arr, int k, int low, int high){
    if(low < high){
        int mid = low + (high - low) / 2;
        if(high - low <= k){
            merge_sort(arr, k, low, mid);
            merge_sort(arr, k, mid + 1, high);
        } else {
            insertion_sort(arr, low, mid);
            insertion_sort(arr, mid + 1, high);
        }
        merge(arr, low, mid, high);
    }
}


int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for(int i = 0; i < n;  i++)
        scanf("%d", &arr[i]);

    merge_sort(arr, k, 0, n - 1);

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
