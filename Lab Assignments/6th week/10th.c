#include<stdio.h>

void merge(int arr[][2], int low, int mid, int high){
    int n1 = mid - low + 1, n2 = high - mid;
    int left[n1][2], right[n2][2];
    for(int i = 0; i < n1; i++){
        left[i][0] = arr[low + i][0];
        left[i][1] = arr[low + i][1];
    }
    for(int i = 0; i < n2; i++){
        right[i][0] = arr[mid + i + 1][0];
        right[i][1] = arr[mid + i + 1][1];
    }

    int i = 0, j = 0, k = low;
    while(i < n1 && j < n2){
        if(left[i][0] <= right[j][0]){
            arr[k][0] = left[i][0];
            arr[k++][1] = left[i++][1];
        } else {
            arr[k][0] = right[j][0];
            arr[k++][1] = right[j++][1];
        }
    }

    while(i < n1){
        arr[k][0] = left[i][0];
        arr[k++][1] = left[i++][1];
    }
    while(i < n2){
        arr[k][0] = right[j][0];
        arr[k++][1] = right[j++][1];
    }
}

void merge_sort(int arr[][2], int low, int high){
    if(low < high){
        int mid = low + (high - low) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int arr[n][2];
    for(int i = 0 ; i < n ; i++){
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    merge_sort(arr, 0, n - 1);

    int k = 0;
    for(int i = 1; i < n ; i++){
        if(arr[i][0] <= arr[k][1]){
            arr[k][1] = arr[k][1] > arr[i][1] ? arr[k][1] : arr[i][1];
        } else {
            k++;
            arr[k][0] = arr[i][0];
            arr[k][1] = arr[i][1];
        }
    }
    k++;
    printf("%d\n", k);

    for(int i = 0; i < k; i++){
        printf("%d %d\n", arr[i][0], arr[i][1]);
    }

}
