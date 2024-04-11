#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    
    char arr[n+1];
    scanf(" %[^\n]",arr);
    
    int count=0;
    for(int i=n-1;i>=0;i--){
        if(arr[i]=='a' ||arr[i]=='e' ||arr[i]=='i' ||arr[i]=='o' ||arr[i]=='u' ){
            count++;
        }
    }
    
    char arr1[count+1];
    int j=0;
    for(int i=n-1;i>=0;i--){
        if(arr[i]=='a' ||arr[i]=='e' ||arr[i]=='i' ||arr[i]=='o' ||arr[i]=='u' ){
            arr1[j]=arr[i];
            j++;
        }
    }
    arr1[count]='\0';
    
    int k=0;
    for(int i=0;i<n;i++){
        if(arr[i]==97 ||arr[i]==101 ||arr[i]==105 ||arr[i]==111 ||arr[i]==117 ){
            arr[i]=arr1[k];
            k++;
        }
    }
    
    printf("%s\n",arr);
    
    return 0;
}