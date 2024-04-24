#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int first;
    int second;
} pair;


void counting_sort(pair *arr, int n, int e){

    int count[n + 1];
    pair output[n];
    for(int i = 0 ; i <= n; i++)
        count[i] = 0;

    for(int i = 0; i < n; i++)
        if(e == 0)
            count[arr[i].second]++;
        else
            count[arr[i].first]++;
    
    for(int i = 1; i <= n ; i++)
        count[i] = count[i] + count[i - 1];

    for(int i = n - 1; i >= 0 ;i--)
        if(e == 0)
            output[--count[arr[i].second]] = arr[i];
        else
            output[--count[arr[i].first]] = arr[i];
        
    for(int i = 0; i < n; i++)
        arr[i] = output[i];

}


void radix_sort_pair(pair *arr, int n){
    counting_sort(arr, n, 0);
    counting_sort(arr, n, 1);
}


int main(){
    int n;
    scanf("%d", &n);

    pair *arr = (pair *)malloc(n * sizeof(int));

    for(int i = 0 ; i < n ; i++)
        scanf("%d", &arr[i].first);

    for(int i = 0 ; i < n; i++)
        scanf("%d", &arr[i].second);

    radix_sort_pair(arr, n);

    for(int i = 0 ; i < n ; i++)
        printf("%d ", arr[i].first);

    printf("\n");

    for(int i = 0 ; i < n; i++)
        printf("%d ", arr[i].second);
}
