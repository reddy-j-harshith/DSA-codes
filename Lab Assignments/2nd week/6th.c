#include<stdio.h>
#include<stdlib.h>

int sum(int l, int r, int* rev){
    int sum = 0;
    for(int i = l - 1; i < r; i++){
        sum += rev[i];
    }
    return sum;
}

int main(){
    int n, q;
    scanf("%d %d", &n, &q);

    int* rev = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &rev[i]);
    }

    int queries[q][2];
    for(int i = 0; i < q; i++){
        scanf("%d %d", &queries[i][0], &queries[i][1]);
    }

    for(int i = 0; i < q; i++){
        printf("%d\n", sum(queries[i][0], queries[i][1], rev));
    }
}