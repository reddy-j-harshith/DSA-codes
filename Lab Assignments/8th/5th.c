#include<stdio.h>
#include<stdbool.h>
#define MAX 1000000

char Deq[MAX];
char Stack[MAX];


int front = -1, back = 0, size = 0;
int top = 0;

int n, k;


void push(char digit){
    if(top < n - k)
        Stack[top++] = digit;
}

void pop(){
    if(top > 0)
        Stack[--top] = '\0';
}

char top_element(){
    if(top > 0)
        return Stack[top - 1];
    else return '\0';
}


bool isEmpty(){
    return size == 0;
}

bool isFull(){
    return size == k;
}

void enqueue_front(char number){
    if(!isFull()){
        size++;
        front++;
        if(front == k) front = 0;
        Deq[front] = number;
    }
}

void enqueue_back(char number){
    if(!isFull()){
        size++;
        back--;
        Deq[back--] = number;
        if(back == -1) back = k - 1;
    }
}

void dequeue_front(){
    if(!isEmpty()){
        size--;
        Deq[front] = '0';
        front--;
        if(front == 0) front = k - 1;
    }
}

void dequeue_back(){
    if(!isEmpty()){
        size--;
        Deq[back] = '0';
        back++;
        if(back == k) back = 0;
    }
}

char back_element(){
    if(!isEmpty()){
        return Deq[back];
    }
}

void profit(char number[]){

    char new_number[n - k];

    for(int i = 0; i < n - k; i++)
        new_number[i] = '0';

    int count = 0;
    for(int i = 0; i < k; i++){
        if(number[i] == '0') // Contraception for leading zeros
            count++;
        enqueue_front(number[i + count]);
    }

    for(int i = n - 1; i >= count + k; i--){
        push(number[i]);
    }

    count = 0;

    for(int i = 0; i < n - k; i++){
        count++;
        if(top_element() > back_element()){
            new_number[i] = back_element();
            dequeue_back();
            enqueue_back(top_element());
            pop();
            break;
        } else if(top_element() < back_element()){
            new_number[i] = top_element();
            dequeue_back();
            enqueue_back(top_element());
            pop();
            break;

        } else {
            new_number[i] = back_element();
            dequeue_back();
            enqueue_front(top_element());
            pop();
        }
    }

    for(int i = count; i < n - k; i++){
        new_number[i] = top_element();
        pop();
    }
    for(int i = 0; i < n - k; i++)
        printf("%c", new_number[i]);

}



int main(){

    scanf("%d %d", &n, &k);
    char number[n];
    scanf(" %s", number);

    profit(number);

}