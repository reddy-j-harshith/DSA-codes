#include<stdio.h>

void merge(int* arr1, int* arr2, int n1, int n2){
    int ptr1 = 0, ptr2 = 0;
    for(int i = 1; i <= (n1 + n2); i++){
        if(ptr1 < n1 && (ptr2 >= n2 || arr1[ptr1] <= arr2[ptr2])){
            printf("%d ", arr1[ptr1]);
            ptr1++;
        } else{
            printf("%d ", arr2[ptr2]);
            ptr2++;
        }

    }
}

int main(){
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    int arr1[n1], arr2[n2];
    for(int i = 0; i < n1; i++)
        scanf("%d", &arr1[i]);

    for(int i = 0; i < n2; i++)
        scanf("%d", &arr2[i]);
    
    merge(arr1, arr2, n1, n2);
    return 0; 
}

