#include<stdio.h>
#define MAX 1000000

int stack[MAX], top = 0, min = 0;
int queue[MAX], head = 0, tail = -1, sum = 0, size = 0;

int getMin(){ return min; }

void setMin(int x){ min = x; }

void push(int x){
    if(top == 0){
        stack[top++] = x;
        setMin(x);
    } else if (x < getMin()){
        stack[top++] = (2 * x) - getMin();
        setMin(x);
    } else {
        stack[top++] = x;
    }


    queue[++tail] = x;
    sum += x;
    size++;

}


void pop(){
    if(top > 0){
        int t = stack[--top];
        if(t < min) min = (2 * getMin()) - t;
    }

    if(size > 0){
        int t = queue[head++];
        sum -= t;
        size--;
    }

}

int getAvg(){
    return (sum / size);
}


int main(){
    int q;
    scanf("%d", &q);

    int query[q][2];

    for(int i = 0; i < q; i++){
        int temp;
        scanf("%d", &temp);
        query[i][0] = temp;
        if(temp == 1)
            scanf("%d", &query[i][1]);
        else
        query[i][1] = 0;
    }

    for(int i = 0; i < q; i++){
        if(query[i][0] == 1)
            push(query[i][1]);
        else if(query[i][0] == 2)
            pop();
        else
            printf("%d %d\n", getMin(), getAvg());
    }
}