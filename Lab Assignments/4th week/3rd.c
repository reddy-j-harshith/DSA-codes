#include<stdio.h>

int power(int arr[][2], int n, int k, int sum, int max){
    if(k == 0) return (sum > max) ? sum : max;
    else if(k < 0 || n == 0) return 0;
    int include = power(arr, n - 1, k - arr[n - 1][1], sum + arr[n - 1][0], max);
    int exclude = power(arr, n - 1, k, sum, max);
    return include > exclude ? include : exclude;


}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n][2];
    for(int i = 0 ; i < n; i++)
        scanf("%d", &arr[i][0]);

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i][1]);
    int maximumPower = power(arr, n, k, 0, 0);
    printf("%d", maximumPower);
}