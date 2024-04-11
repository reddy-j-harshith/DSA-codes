#include<stdio.h>


int sliding(int* arr, int n, int k, int x){
    int windowSum = 0, count = 0;

    for(int right = 0 ; right < k; right++)
        windowSum += arr[right];

    for(int right = k; right <= n ; right++ ){
        if(windowSum / k >= x){
            count++;
        }

        windowSum += arr[right] - arr[right - k];
    }
    return count;
}

int main(){
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);
    int arr[n];
    for(int i = 0 ; i <n ; i ++)
        scanf("%d", &arr[i]);

    printf("%d", sliding(arr, n, k, x));
}