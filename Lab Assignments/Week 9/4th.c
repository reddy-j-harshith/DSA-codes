#include<stdio.h>
#include<math.h>

int max(int a, int b) { return a > b ? a : b;}

int preIndex = 1;
int maxIdx = 1;
void tree_construct(int *tree, int *in, int *pre, int is, int ie, int idx){

    if(is > ie) { tree[idx] = -1; return; }
    tree[idx] = pre[preIndex++];
    maxIdx = max(idx, maxIdx);

    int inIndex = 0;
    for(int i = is; i <= ie; i++){
        if(in[i] == tree[idx]){
            inIndex = i;
            break;
        }
    }

    tree_construct(tree, in, pre, is, inIndex - 1, 2 * idx);
    tree_construct(tree, in, pre, inIndex + 1, ie, (2 * idx) + 1);
    return;
}


int main(){
    int n;
    scanf("%d", &n);

    int in[n + 1];
    int pre[n + 1];

    for(int i = 1; i <= n; i++)
        scanf("%d", &in[i]);

    for(int i = 1; i <= n; i++)
        scanf("%d", &pre[i]);

    int len;
    for(len = 1; len < n ; len *= 2);

    int tree[len + 1];
    int idx = 1;

    tree_construct(tree, in, pre, 1, n, idx);

    for(int i = 1; i <= maxIdx; i++){
        printf("%d ", tree[i]);
    }
}