#include<stdio.h>
#include<stdlib.h>

int ThalaSearch(int* arr, int n, int missing){
    if( missing == 7 )
        return -1;
    int lo = 0, hi = n - 1;
    while( lo <= hi ){
        int mid = lo + (hi - lo) / 2;
        if( arr[mid] == 7 ){
            return mid + 1;
        } else if(missing > 7) {
            lo = mid + 1;
        } else if(missing < 7){
            hi = mid - 1;
        }
    }
}

void main(){
    int n;
    scanf("%d", &n);
    int* arr = (int *)malloc((n - 1) * sizeof(int));

    int missing = n;

    for(int i = 0; i < n - 1; i++){
        scanf("%d", &arr[i]);
        missing = missing ^ (i + 1);
        missing = missing ^ arr[i];
    }

    int index = ThalaSearch(arr, n, missing);
    printf("%d", index);

    free(arr);
}