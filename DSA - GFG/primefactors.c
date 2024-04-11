#include<stdio.h>

void factors(int n){
    for(int i = 2; i <= n ; i++){
        while( n % i == 0 ){
            printf("%d\n", i);
            n /= i;
        }
    }
    return;
}

int main(){
    int n;
    scanf("%d", &n);
    factors(n);
}