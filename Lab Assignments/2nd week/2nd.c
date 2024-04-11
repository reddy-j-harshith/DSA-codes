#include<stdio.h>
#include<stdlib.h>

int BinarySearch(int n, int key, int* arr){
    int lo = 0, hi = n - 1;
    while( lo <= hi ){
        int mid = lo + (hi - lo) / 2;
        if((arr[mid - 1] < arr[mid]) && (arr[mid] < arr [mid + 1])){
            lo = mid + 1;
        } else if((arr[mid - 1] > arr[mid]) && (arr[mid] > arr [mid + 1])) {
            hi = mid - 1;
        } else {
            return mid + 1;
        }
    
   }
}

void main(){
    int n;
    scanf("%d", &n);
    int* arr = (int *)malloc(n * sizeof(int));
    int temp;

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        if( i == 0 || temp < arr[i] ){
            temp = arr[i];
        }
    }

    int index = BinarySearch(n, temp, arr);
    printf("%d", index);
}