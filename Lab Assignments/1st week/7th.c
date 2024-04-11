#include<iostream>

using namespace std;

int fun(int n, int k){
    if(n == 0 || n == 1) return k;
    return fun(n - 1, n * k);
}

int main(){
    int n = 6;
    cout<<fun(n, 6);
}