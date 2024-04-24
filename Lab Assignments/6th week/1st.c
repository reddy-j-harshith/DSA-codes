#include<stdio.h>



void merge(int *arr, int low, int mid, int high){
    int n1 = mid - low + 1, n2 = high - mid;
    int left[n1], right[n2];
    for(int i = 0; i < n1; i++) { left[i] = arr[i + low]; }
    for(int i = 0; i < n2; i++) { right[i] = arr[i + mid + 1]; }

    int i = 0, j = 0, k = low;
    while(i < n1 && j < n2){
        if(left[i] <= right[j]) { arr[k++] = left[i++]; }
        else                    { arr[k++] = right[j++]; }
    }

    while(i < n1) arr[k++] = left[i++];
    while(j < n2) arr[k++] = right[j++];

}

void merge_sort(int *arr, int low, int high){
    if(low < high){
        int mid = low + (high - low) / 2;
        merge_sort(arr, 0, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}


int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    merge_sort(arr, 0, n - 1);

    for(int i = 0 ; i < n; i++)
        printf("%d ", arr[i]);
}
