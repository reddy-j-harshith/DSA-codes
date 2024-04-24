#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node **queue;
int head, tail, cap, size;

void initialize(int n, int i){
    head = 0;
    tail = -1;
    if(i == 1 && queue != NULL){
        free(queue);
    }
    queue = (struct Node **)malloc(n * sizeof(struct Node));
    cap = n;
    size = 0;
}

struct Node *createNode(int n){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node -> left = NULL;
    node -> right = NULL;
    node -> key = n;
    return node;
}

// insert at rear and dequeue at front

void push(struct Node *n){
    if(size < cap){
        tail = (tail + 1) % cap;
        queue[tail] = n;
        size++;
    }
}

void pop(){
    if(size > 0){
        head = (head + 1) % cap;
        size--;
    }
}

bool empty(){
    return size == 0;
}

struct Node *front(){
    if(!empty())
        return queue[head];
}

int getSize(){
    return size;
}

struct Node *tree_creation(int *arr, int n){

    initialize(n, 0);
    struct Node *node = createNode(arr[0]);
    push(node);
    struct Node *root = node;

    int i = 1;
    while(!empty() && i < n - 1){
        int count = getSize();
        for(int j = 0; j < size; j++){
            struct Node *curr = front();
            pop();

            if(i < n && arr[i] != -1){
                struct Node *node = createNode(arr[i]);
                curr -> left = node;
                push(node);
            } else {
                curr -> left = NULL;
            }
            i++;

            if(i < n && arr[i] != -1){
                struct Node *node = createNode(arr[i]);
                curr -> right = node;
                push(node);
            } else {
                curr -> right = NULL;
            }

            i++;
        }
    }

    return root;
}

bool pre_order_search(struct Node *root, int k){

    if(root != NULL){
        if(root -> key == k)
            return true;
        return pre_order_search(root -> left, k) || pre_order_search(root -> right, k);
    } else {
        return false;
    }
}

struct Node *LeastCommonAnc(struct Node *root, int A, int B){

    initialize(cap, 1);
    push(root);

    struct Node *node = NULL;
    while(!empty()){
        struct Node *curr = front();
        pop();

        if(pre_order_search(curr, A) && pre_order_search(curr, B))
            node = curr;
    
        if(curr -> left != NULL)
            push(curr -> left);
        if(curr -> right != NULL)
            push(curr -> right);
    }
    return node;
}

int main(){
    int n, A, B;
    scanf("%d %d %d", &n, &A, &B);

    int *arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node *tree = tree_creation(arr, n);
    struct Node *LCA = LeastCommonAnc(tree, A, B);

    printf("%d ", LCA -> key);
}