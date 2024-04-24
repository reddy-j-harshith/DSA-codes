#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct{

    int top;
    int size;
    int *arr;
    int cap;
    
} stack;

void initialize(stack *stk, int cap){
    
    stk -> top = 0;
    stk -> size = 0;
    stk -> arr = (int *)malloc(sizeof(int) * cap);
    stk -> cap = cap;
}

void push(stack *s, int x){
    if(s -> size < s -> cap){
        s -> arr[s -> top++] = x;
        s -> size++;
    }
}

void pop(stack *s){
    if(s -> size > 0){
        s -> arr[--(s -> top)] = 0;
        s -> size--;
    }
}

bool empty(stack s){
    return s.size == 0;
}

int top(stack s){
    return (empty(s) ? -1 : s.arr[(s.top) - 1]);
}

void nextGreater(int *arr, int n){
    stack s;
    initialize(&s, n);

    int vec[n];

    push(&s, n - 1);
    vec[n - 1] = 0;

    for(int i = n - 2; i >= 0; i--){
        while(empty(s) == false && arr[i] >= arr[top(s)]){
            pop(&s);
        }

        int temp = (empty(s) ? 0 : top(s) - i);
        vec[i] = temp;
        push(&s, i);
    }
    
    for(int i = 0; i < n; i++){
        printf("%d ", vec[i]);
    }
    printf("\n");

}

void nextSmaller(int *arr, int n){
    stack s;
    initialize(&s, n);

    int vec[n];

    push(&s, n - 1);
    vec[n - 1] = 0;

    for(int i = n - 2; i >= 0; i--){
        while(empty(s) == false && arr[i] <= arr[top(s)]){
            pop(&s);
        }

        int temp = (empty(s) ? 0 : top(s) - i);
        vec[i] = temp;
        push(&s, i);
    }
    for(int i = 0; i < n; i++){
        printf("%d ", vec[i]);
    }

}

int main(){
    int n;
    scanf("%d", &n);
    int *arr1 = (int *)malloc(n * sizeof(int));
    int *arr2 = (int *)malloc(n * sizeof(int));


    for(int i = 0; i < n; i++){
        scanf("%d", &arr1[i]);
        arr2[i] = arr1[i];
    }

    nextGreater(arr1, n);
    nextSmaller(arr2, n);


}