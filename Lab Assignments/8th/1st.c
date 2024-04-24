#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAX_M 100000

char Stack[MAX_M];
int top = 0;

void push(char element){
    if(top < MAX_M)
        Stack[top++] = element;
}

void pop(){
    if(top > 0){
        Stack[--top] = '\0';
    }
}

bool isEmpty(){
    return top == 0;
}

char top_element(){
    if(top > 0)
        return Stack[top - 1];
    else
        return '-';
}

bool paranthesis_check(char input[]){

    for(int i = 0; i < strlen(input); i++){
        if(input[i] == '{' || input[i] == '[' || input[i] == '('){
            push(input[i]);
        } else if (input[i] == '}' || input[i] == ']' || input[i] == ')'){
            if(isEmpty())
                return false;
            else
                if((input[i] == '}' && top_element() == '{')
                 || (input[i] == ']' && top_element() == '[') 
                 || (input[i] == ')' && top_element() == '(')) pop();
                else
                    return false;
        }
        else continue;
    }
    return isEmpty();
}

int main(){

    char input[MAX_M];
    scanf("%s", input);

    printf("%s \n", paranthesis_check(input) ? "YES" : "NO");
    
}