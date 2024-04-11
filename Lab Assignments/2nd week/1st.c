#include<stdio.h>
#include<stdlib.h>

int BinarySearch(int n, int key, int* arr){
    int lo = 0, hi = n - 1;
    while( lo <= hi ){
        int mid = lo + (hi - lo) / 2;
        if( key > arr[mid] ){
            lo = mid + 1;
        } else if( key < arr[mid] ) {
            hi = mid - 1;
        } else {
            return mid + 1;
        }
    return -1;
   }
}

void main(){
    int n, fav;
    scanf("%d %d", &n, &fav);
    int* arr = (int *)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int index = BinarySearch(n, fav, arr);
    printf("%d", index);
}