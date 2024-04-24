#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};


struct Node *insert_end(struct Node *head, int data){
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

void print_current(struct Node *head){
    if(head == NULL) return;
    printf("%d\n", head -> data);
}

struct Node *insert_next(struct Node *head, int data){
    if(head -> next == NULL){
        head = insert_end(head, data);
    }
    else{
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp -> data = data;
        temp -> prev = head;
        temp -> next = head -> next;

        head -> next -> prev = temp;
        head -> next = temp;
    }
    return head;
}

struct Node *play_next(struct Node *head){
    if(head -> next == NULL) return head;
    else return head -> next;
}

struct Node *play_previous(struct Node *head){
    if(head -> prev == NULL) return head;
    else return head -> prev;
}

struct Node *delete_current(struct Node *head){
    if(head -> next == NULL) {
        struct Node *curr = head -> prev;
        free(head);
        while(curr -> prev != NULL){
            curr = curr -> prev;
        }
        return curr;
    } else {
        struct Node* curr = head -> next;
        curr -> prev = head -> prev;
        if(head -> prev != NULL)
            head -> prev -> next = curr;
        free(head);
        return curr;
    }
}

int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    struct Node *head = NULL;
    for(int i = 1; i <= n; i++){
        int data;
        scanf("%d", &data);
        head = insert_end(head, data);
    }

    int query[q][2];
    for(int i = 0; i < q; i++){
        scanf("%d", &query[i][0]);

        if(query[i][0] == 2 || query[i][0] == 3)
            scanf("%d", &query[i][1]);
        else
            query[i][1] = 0;
    }
    printf("\n");
    for(int i = 0; i < q; i++){
        if(query[i][0] == 2){
            head = insert_next(head, query[i][1]);
        } else if (query[i][0] == 3) {
            head = insert_end(head, query[i][1]);
        }
        else if(query[i][0] == 1)
            print_current(head);
        else if(query[i][0] == 4)
            head = play_next(head);
        else if(query[i][0] == 5)
            head = play_previous(head);
        else if(query[i][0] == 6)
            head = delete_current(head);


    }
    return 0;
}