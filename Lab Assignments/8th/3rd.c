#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MOD 1000000007

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

int maxSum(int *arr, int n){

   int sum = 0;

    initialize(n);
    for(int i = 0; i < n; i++){
        while(!empty() && arr[peek()] >= arr[i]){
            int tp = pop();
            int left = empty() ? 0 : peek() + 1;
            int right = i;
            sum = sum + arr[tp] * (tp - left + 1) * (right - tp) % 1000000007;
            sum = sum % 1000000007;

        }
        push(i);
    }
    while(!empty()){
            int tp = pop();
            int left = empty() ? 0 : peek() + 1;
            int right = n;
            sum = sum + arr[tp] * (tp - left + 1) * (right - tp) % 1000000007;
            sum = sum % 1000000007;
    }
    return sum;
}

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int result = maxSum(arr, n);
    printf("%d\n", result);
    return 0;
}