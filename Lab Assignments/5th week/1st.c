#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Node{
    int data;
    struct Node *next;
};


struct Node *addNumbers(struct Node *head1, struct Node *head2);


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

struct Node *addItem(struct Node *head, int data){

    struct Node *new_head = (struct Node*)malloc(sizeof(struct Node));
    new_head -> data = data;
    new_head -> next = head;
    return new_head;
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

    struct Node* new = addNumbers(head1, head2);
    printLinkedList(new);

}


struct Node *addNumbers(struct Node *head1, struct Node *head2){

    struct Node *new_head = NULL;
    struct Node *temp1 = head1, *temp2 = head2;
    int carry = 0;
    while(temp1 != NULL || temp2 != NULL){

        int A = (temp1 != NULL) ? (temp1 -> data) : 0;
        int B = (temp2 != NULL) ? (temp2 -> data) : 0;

        if(temp2 != NULL) B = temp2 -> data;
        else              B = 0;

        int add = A + B + carry;
        carry = add / 10;
        add = add % 10;

        new_head = insertAtEnd(new_head, add);

        if(temp1 != NULL) temp1 = temp1 -> next;
        if(temp2 != NULL) temp2 = temp2 -> next;

    }

    if(carry == 1) 
        new_head = insertAtEnd(new_head, carry);
    return new_head;
}

