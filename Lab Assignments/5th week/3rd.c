#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *next;
};


struct Node *reverseLL(struct Node *head);


struct Node *addItem(struct Node *head, int data){

    struct Node *new_head = (struct Node*)malloc(sizeof(struct Node));
    new_head -> data = data;
    new_head -> next = head;
    return new_head;
}



struct Node *insertAtEnd(struct Node *head, int data){

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = NULL;

    if(head == NULL) return temp;

    struct Node *curr = head;
    while(curr -> next != NULL)
        curr = curr -> next;

    curr -> next = temp;
    return head;

}



void printLinkedList(struct Node *head){
    struct Node *curr = head;
    while(curr != NULL){
        printf("%d ", curr -> data);
        curr = curr -> next;
    }
    printf("\n");
}


int main(){
    int n;
    scanf("%d", &n);

    struct Node *head = NULL;

    for(int i = 1; i <= n; i++){
        int temp;
        scanf("%d", &temp);
        head = insertAtEnd(head, temp);
    }

    head = reverseLL(head);
    printLinkedList(head);
}

struct Node *reverseLL(struct Node *head){

    struct Node *prev = NULL, *curr = head;
    while(curr != NULL){
        struct Node *temp = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}