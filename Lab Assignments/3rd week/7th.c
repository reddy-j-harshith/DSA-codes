#include <stdio.h>

int value(int n,int arr[]){
    int panda1 = arr[0], panda2 = arr[n - 1];
    int maxval = 0;
    int left = 0, right = n - 1;
    while(left < right){
        if(panda1 < panda2){
            panda1 += arr[left + 1];
            left++;
        }
        else if(panda1 > panda2){
            panda2 += arr[right - 1];
            right--;
        }
        else{
            maxval = panda1;
            panda1 += arr[left + 1];
            left++;
        }
    }
    return maxval;
    
}

int main(){
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }    
    printf("%d", value(n,arr));
    return 0;
}