#include<stdio.h>

float root(float n){
    float lo = 0.0, hi = n;
    float epsilon = 0.000001;
    while(hi - lo > epsilon){
        float mid = (lo + hi)/2.0;
        float square = mid * mid;
        if(square == n){
            return mid;
        } else if( square < n ){
            lo = mid;
        } else{
            hi = mid;
        }
    }
    return (lo + hi) / 2.0;
}

void main(){
    float n;
    scanf("%f", &n);

    float result = root(n);
    printf("%f", result);
}