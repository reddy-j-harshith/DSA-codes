#include<stdio.h>
#include<math.h>
#include<stdbool.h>

int getDepth(int size){
    return (int)(log2(size));
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int *arr, int low, int mid, int high){
    int n1 = mid - low + 1, n2 = high - mid;
    int left[n1], right[n2];
    for(int i = 0; i < n1; i++) left[i] = arr[low + i];
    for(int i = 0; i < n2; i++) right[i] = arr[mid + i + 1];

    int i = 0, j = 0, k = low;
    while(i < n1 && j < n2){
        if(left[i] <= right[j]) arr[k++] = left[i++];
        else                    arr[k++] = right[j++];
    }

    while(i < n1) arr[k++] = left[i++];
    while(j < n2) arr[k++] = right[j++];
}

void merge_sort(int *arr, int low, int high){
    if(low < high){
        int mid = low + (high - low) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}


int partition(int *arr, int low, int high){
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
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





void nomki_sort(int *arr, int low, int high, int level, int depth){
    if(low < high){
        if(level <= depth){
            int location = partition(arr, low, high);
            nomki_sort(arr, low, location, level + 1, depth);
            nomki_sort(arr, location + 1, high, level + 1, depth);
        }
    } else {
        merge_sort(arr, low, high);
    }
}

int main(){

    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &arr[i]);

    nomki_sort(arr, 0, n - 1, 0, n);

    for(int i = 0 ; i < n; i++)
        printf("%d ", arr[i]);
}
