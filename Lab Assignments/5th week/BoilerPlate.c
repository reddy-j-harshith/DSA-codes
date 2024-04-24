#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *next;
};


struct Node *insertEndCLL(struct Node *head, int data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp -> data = data;
    if(head == NULL){
        temp -> next = temp;
    } else {
        temp -> next = head -> next;
        head -> next = temp;

        int i = head -> data;
        head -> data = temp -> data;
        temp -> data = i;
    }
    return temp;
}

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

void printCLL(struct Node *head){
    struct Node *curr = head -> next;
    printf("%d ", head -> data);


    while(curr != head){
        printf("%d ", curr -> data);
        curr = curr -> next;
    }
    printf("\n");
}



int main(){
    
}
