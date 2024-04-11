#include <stdio.h>

int main(){
    int i,j,n;
    
    scanf("%d",&n);
    
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    int max=0;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if((arr[j]-arr[i])>max){
                max=arr[j]-arr[i];
            }
        }
    }
    printf("%d",max);
    
    return 0;
}