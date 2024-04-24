#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *next;
};

struct Node *merge_ll(struct Node *head1, struct Node *head2);

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
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node *head1 = NULL, *head2 = NULL;

    for(int i = 1; i <= n; i++){
        int temp;
        scanf("%d", &temp);
        head1 = insertAtEnd(head1, temp);
    }

    for(int i = 1; i <= m; i++){
        int temp;
        scanf("%d", &temp);
        head2 = insertAtEnd(head2, temp);
    }

    struct Node* new_head = merge_ll(head1, head2);
    printLinkedList(new_head);
}



struct Node *merge_ll(struct Node *head1, struct Node *head2){

    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    struct Node *head = (head1 -> data > head2 -> data) ? (head2) : (head1);

    struct Node *tail = head;
    if(head1 == head){
        head1 = head1 -> next;
    } else {
        head2 = head2 -> next;
    }

    while(head1 != NULL && head2 != NULL){

        if(head1 -> data > head2 -> data){
            tail -> next = head2;
            head2 = head2 -> next;
        } else {
            tail -> next = head1;
            head1 = head1 -> next;
        }
        tail = tail -> next;
    }

    if(head1 == NULL)
        tail -> next = head2;
    else    
        tail -> next = head1;    
    return head;
}

