#include<stdio.h>
#include<limits.h>

int min(int a, int b){ return a < b ? a : b; }
int max(int a, int b){ return a > b ? a : b; }

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int small = INT_MAX;
    int large = INT_MIN;
    int dif = 0;

    for(int i = 0; i < n; i++){
        if(small > arr[i]){
            small = arr[i];
            large = arr[i];
        } else {
            large = max(large, arr[i]);
        }
        dif = max(dif, large - small);
    }

    printf("%d ", dif);
}
