#include<stdio.h>

int count(int k, int* arr, int n, int i){
    if(k == 0) return 1;
    
    if(k < 0 || i == n) return 0;

    int include = count(k - arr[i], arr, n, i);
    int exclude = count(k, arr, n, i + 1);

    return include + exclude;
}


int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for(int i = 0; i < n; i ++)
        scanf("%d", &arr[i]);

    int cnt = count(k, arr, n, 0);
    printf("%d", cnt);


}