#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};





struct Node *insertBegin(struct Node *head, int data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp -> prev = NULL;
    temp -> next = head;
    temp -> data = data;
    if(head != NULL)
        head -> prev = temp;
    return temp;
}


struct Node *insertEnd(struct Node *head, int data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = NULL;
    if(head == NULL){
        temp -> prev = NULL;
        return temp;
    }

    struct Node *curr = head;
    while(curr -> next != NULL)
        curr = curr -> next;

    curr -> next = temp;
    temp -> prev = curr;
    return head;
}


struct Node *deleteBegin(struct Node *head){
    if(head == NULL || head -> next == NULL) {\
        free(head); 
        return head; 
    }

    struct Node *temp = head -> next;
    head -> next = NULL;
    temp -> prev = NULL;
    free(head);
    return temp;
}


struct Node *deleteEnd(struct Node *head){
    if(head == NULL || head -> next == NULL){ 
        free(head);
        return NULL; 
    }

    struct Node *curr = head;
    while(curr -> next != NULL){
        curr = curr -> next;
    }

    curr -> prev -> next = NULL;
    curr -> prev = NULL;
    free(curr);
    return head;
}


void printDLL(struct Node *head){
    if(head == NULL) { printf("-1\n"); return; }
    struct Node *curr = head;
    while(curr != NULL){
        printf("%d ", curr -> data);
        curr = curr -> next;
    }
    printf("\n");
    return;
}

void printDLLReverse(struct Node *head){
    if(head == NULL){ printf("-1"); return; }
    if(head -> next == NULL) {printf("%d\n", head -> data); return;}

    struct Node *curr = head;

    while(curr -> next != NULL){
        curr = curr -> next;
    }

    while(curr != NULL){
        printf("%d ", curr -> data);
        curr = curr -> prev;
    }
    printf("\n");
    return;
}





int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    struct Node *head = NULL;
    for(int i = 1; i <=n; i++){
        int data;
        scanf("%d", &data);
        head = insertEnd(head, data);
    }

    int query[q][2];
    for(int i = 0; i < q; i++){
        scanf("%d", &query[i][0]);

        if(query[i][0] == 1 || query[i][0] == 2)
            scanf("%d", &query[i][1]);
        else
            query[i][1] = 0;
    }

    for(int i = 0; i < q; i++){
        if(query[i][0] == 1){
            head = insertBegin(head, query[i][1]);
        } else if (query[i][0] == 2) {
            head = insertEnd(head, query[i][1]);
        }
        else if(query[i][0] == 3)
            head = deleteBegin(head);
        else if(query[i][0] == 4)
            head = deleteEnd(head);
        else if(query[i][0] == 5)
            printDLL(head);
        else if(query[i][0] == 6)
            printDLLReverse(head);


    }
    return 0;
}