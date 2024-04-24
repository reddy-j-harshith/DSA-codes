#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};


struct Node *insertBegin(struct Node *head, int data){

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = head;
    return temp;
}


int caughtNode(struct Node *head, int a, int b){

    struct Node *slow = head; // jim
    for(int i = 1; i < b; i++)
        slow = slow -> next;

    struct Node *fast = head; // Dwight
    for(int i = 1; i < a; i++)
        fast = fast -> next;

    while(slow != fast){


        if(slow -> next == NULL) slow = head;
        else slow = slow -> next;

        if(fast -> next == NULL) fast = head -> next;
        else if(fast -> next -> next == NULL) fast = head;
        else fast = fast -> next -> next;

    }

    return slow -> data;

}

int main(){

    int n, a ,b;
    scanf("%d %d %d", &n, &a, &b);

    struct Node *head = NULL;
    for(int i = n; i > 0; i--)
        head = insertBegin(head, i);

    int result = caughtNode(head, a, b);
    
    printf("%d", result);
}