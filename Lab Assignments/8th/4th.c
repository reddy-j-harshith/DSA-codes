#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int *stack, top, cap;

void initialize(int n){
    cap = n;
    stack = (int *)malloc(sizeof(int) * cap);
    top = 0;
}

bool empty(){ return top == 0; }

bool full(){ return top == cap; }

void push(int x){ if(!full()){ stack[top++] = x; } }

int pop(){ if(!empty()) return stack[--top]; else return -1;}

int peek(){ if(!empty()) return stack[top - 1]; else return -1;}

int max(int a, int b){ return a > b ? a : b; }

int maxArea(int *arr, int n){

    initialize(n);
    int res = 0;
    for(int i = 0; i < n; i++){
        while(!empty() && arr[peek()] >= arr[i]){
            int tp = pop();
            int curr = arr[tp] * (empty() ? i : (i - peek() - 1));
            res = max(res, curr);
        }
        push(i);
    }
    while(!empty()){
        int tp = pop();
        int curr = arr[tp] * (empty() ? n : (n - peek() - 1));
        res = max(res, curr);
    }
    return res;
}

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int result = maxArea(arr, n);
    printf("%d\n", result);
    return 0;
}