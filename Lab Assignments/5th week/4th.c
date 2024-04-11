#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *next;
};


struct Node *rotateK(struct Node *head, int n, int k);

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
    int n, k;
    scanf("%d %d", &n, &k);

    struct Node *head = NULL;

    for(int i = 1; i <= n; i++){
        int temp;
        scanf("%d", &temp);
        head = insertAtEnd(head, temp);
    }

 
    struct Node *new_head = rotateK(head, n, k);
    printLinkedList(new_head);
}



struct Node *rotateK(struct Node *head, int n, int k){
    if(head == NULL || k == 0) return head;
    
    int rotate = k % n;
    int i = 1;
    struct Node *KthNode = head;
    while(i < rotate){
        KthNode = KthNode -> next;
        i++;
    }

    struct Node *last = head;
    while(last -> next != NULL)
        last = last -> next;

    last -> next = head;

    struct Node *temp = KthNode;
    KthNode = KthNode -> next;
    temp -> next = NULL;
    return KthNode;

}
