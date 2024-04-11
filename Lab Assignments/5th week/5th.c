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



struct Node *deleteKth(struct Node *head, int n, int k){
    if(head == NULL)
        return NULL;

    if(head -> next == NULL)
        return head;
    
    struct Node *curr = head;
    int i = 1;
    while(i < n % k){
        i++;
        curr = curr -> next;
        if(curr == NULL)
            curr = head;
    }

    
}





int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    struct Node* head = NULL;
    for(int i = 1; i <= n; i++)
        head = insertEndCLL(head, i);

    while(head -> next != NULL)
        head = deleteKth(head, n--, k);

    printf("%d\n", head -> data);

}