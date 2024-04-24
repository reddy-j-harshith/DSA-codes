#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int max(int a, int b){
    return a > b ? a : b;
}

void counting_miss(int *arr, int n, int x, int k){

    int count[x];
    for(int i = 0; i < x; i++)
        count[i] = 0;
    for(int i = 0; i < n ; i++)
        count[arr[i]]++;


    for(int i = 0; i < x; i++){
        for(int j = i + 1; j < x; j++){
            if(count[i] == 0 && count[j] == 0 && i + j == k){
                printf("YES");
                return;
            }
        }
    }

    printf("NO");
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n], x = INT_MIN;
    for(int i = 0 ; i < n; i++){
        scanf("%d", &arr[i]);
        x = max(x, arr[i]);
    }

    counting_miss(arr, n, x + 1, k);
}