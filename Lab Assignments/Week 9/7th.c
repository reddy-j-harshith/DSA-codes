#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    int key;
    struct Node *left;
    struct Node *right;
} Node;

Node *create(int x){
    Node *new = (Node *)malloc(sizeof(Node));
    new -> key = x;
    new -> left = NULL;
    new -> right = NULL;
}

Node *construct(int *arr, int n){

    Node *queue[n + 1];
    int front = 0, rear = -1;

    Node *root = create(arr[0]);
    queue[++rear] = root;

    int i = 1;
    while((rear - front + 1 > 0) && i < n){ // size()

        Node *node = queue[front];
        front++;
        if(i < n && arr[i] != -1){ // For left child
            Node *left = create(arr[i]);
            node -> left = left;
            queue[++rear] = left;
        } else {
            node -> left = NULL;
        } i++;

        if(i < n && arr[i] != -1){ // For right child
            Node *right = create(arr[i]);
            node -> right = right;
            queue[++rear] = right;
        } else {
            node -> right = NULL;
        } i++;

    }
    return root;
}

void in_order(Node *root){
    if(root == NULL) return;

    in_order(root -> left);
    printf("%d ", root -> key);
    in_order(root -> right);
}

Node *lca(Node *root, int A, int B){
    if(root == NULL) return root;
    if(root -> key == A || root -> key == B)
        return root;
    Node *left = lca(root -> left, A, B);
    Node *right = lca(root -> right, A, B);

    if(left != NULL && right != NULL)
        return root;

    return left != NULL ? left : right;
}

int main(){
    int n, A, B;
    scanf("%d %d %d", &n, &A, &B);

    int *arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node *root = construct(arr, n);

    // in_order(root);

    Node *node = lca(root, A, B);
    printf("%d ", node -> key);
}
