#include<stdio.h>

int main(){
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    int minwins = a / b;
    for(int i = 0; i < n; i++){
        int count = 0;
        while(count < minwins && i < n){
            printf("K");
            count++; i++;
        }
        printf("O");
    }
}