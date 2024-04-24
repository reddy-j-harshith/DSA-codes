#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *next;
};


struct Node* removeDups2(struct Node *head){
    if(head == NULL || head -> next == NULL) return head;

    struct Node *curr = head;
    while(curr -> next != NULL){
        if(curr -> next -> data == curr -> data){
            struct Node *temp = curr -> next;
            curr -> next = curr -> next -> next;
            free(temp);
        } else {
            curr = curr -> next;
        }
    }
    return head;
}

struct Node* removeDups(struct Node *head);


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
    
    struct Node *new_head = removeDups2(head);
    printLinkedList(new_head);
}


struct Node* removeDups(struct Node *head){
    if(head == NULL || head -> next == NULL) return head;

    struct Node *curr = head -> next;

    struct Node *new_head = (struct Node*)malloc(sizeof(struct Node));
    new_head -> data = head -> data;
    new_head -> next = NULL;

    struct Node *dup = new_head;
    while(curr != NULL){
        int A = curr -> data;
        int B = dup -> data;
        if(A == B) curr = curr -> next;
        else{
            new_head = insertAtEnd(new_head, curr -> data);
            curr = curr -> next;
            dup = dup -> next;
        }
    }
    return new_head;
}