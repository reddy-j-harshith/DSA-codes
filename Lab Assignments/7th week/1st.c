#include<stdio.h>

void counting_sort(int *arr, int n, int e){

    int count[16] = {0x0};
    int output[n];

    for(int i = 0; i < n; i++){
        int temp = arr[i];
        for(int j = 1; j <= e; j++)
            temp >>= 4;
        count[temp % 0x10]++;
    }

    for(int i = 1; i < 16; i++)
        count[i] = count[i] + count[i - 1];

    for(int i = 0; i < n; i++){
        int temp = arr[i];
        for(int j = 1; j <= e; j++)
            temp >>= 4;
        output[--count[(temp % 0x10)]] = arr[i];
    }

    for(int i = 0 ; i < n; i++)
        arr[i] = output[i];

}


void radix_sort(int *arr, int n, int k){

    for(int i = 0; i < k; i++)
        counting_sort(arr, n, i);

}


int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf(" %x", &arr[i]);

    radix_sort(arr, n, k);

    for(int i = 0 ; i < n; i++)
        printf("%x ", arr[i]);
}