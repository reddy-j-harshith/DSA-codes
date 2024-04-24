#include<stdio.h>

int get_max(int *arr, int n){
    int max = arr[0];
    for(int i = 0; i < n ; i++)
        max = (max > arr[i]) ? max : arr[i];
    return max;
}

void frequency_sort(int *arr, int n){

    int max = get_max(arr, n);
    int count[max + 1];
    for(int i = 0; i <= max; i++)
        count[i] = 0;

    for(int i = 0; i < n; i++)
        count[arr[i]]++;

    int max_freq = get_max(count, max + 1);

    int freq = 1;
    while(freq <= max_freq){
        for(int i = 0 ; i < n ; i++){
            if(count[arr[i]] == freq){
                while(count[arr[i]] > 0){
                    printf("%d ", arr[i]);
                    count[arr[i]]--;
                }
            }
        }
        freq++;
    }

}

int main(){
    int n;
    scanf("%d ", &n);
    int arr[n];
    for(int i= 0 ; i < n ; i++)
        scanf("%d", &arr[i]);
    
    frequency_sort(arr, n);


}