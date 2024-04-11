#include<stdio.h>
#include<stdlib.h>

int shouldJump(int* matrix, int n, int k){
    int lo = 0, hi = n * n;
    while( lo <= hi ){
        int mid = lo + (hi - lo) / 2;
        if( k > matrix[mid] ) lo = mid + 1;
        else if ( k < matrix[mid] ) hi = mid - 1;
        else return 1;
    }
    return 0;
}

int main(){
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    int* matrix = (int *)malloc(n * n * sizeof(int));

    for(int i = 0 ; i < n * n; i++){
        scanf("%d", &matrix[i]);
    }

    int flag = shouldJump(matrix, n, k);
    
    if (flag == 1){
        printf("YES");
    } else {
        printf("NO");
    }
}