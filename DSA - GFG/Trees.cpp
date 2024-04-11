#include<bits/stdc++.h>

using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;

    Node(int k){
        key = k;
        left = right = NULL;      
    }
};

void pre_order(Node *root){

    if(root != NULL){
        cout<<root -> key<<" ";
        pre_order(root -> left);
        pre_order(root -> right);
    }
}

void in_order(Node *root){

    if(root != NULL){
        in_order(root -> left);
        cout<<root -> key<<" ";
        in_order(root -> right);
    }

}

void post_order(Node *root){

    if(root != NULL){
        post_order(root -> left);
        post_order(root -> right);
        cout<<root -> key<<" ";
    }
}

int height_naive(Node *root, int n){
    int count = 0;

    if(root != NULL){
        int left_height = height_naive(root -> left, count);
        count++;
        int right_height = height_naive(root -> right, count);
        
        count += max(left_height, right_height);
    }

    return count;
}

int height(Node *root){
    if(root == NULL)
        return 0;
    else
        return 1 + max(height(root -> left), height(root -> right));
}


// Print the nodes which are k distance from the node.
void printKDist(Node *root, int k){
    
    if(root != NULL && k >= 0){
        if(k == 0) cout<< root -> key<<" ";
        printKDist(root -> left, k - 1);
        printKDist(root -> right, k - 1);
    }

}

void level_order_naive(Node *root){

    int h = height(root);

    for(int i = 0; i < h; i++){
        printKDist(root, i);
    }
}


void level_order(Node *root){
    if(root == NULL) return;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        cout<<curr -> key<<" ";
        if(curr -> left != NULL)
            q.push(curr -> left);
        if(curr -> right != NULL)
            q.push(curr -> right);
    }
}


void line_by_line_self(Node *root){
    if(root == NULL) return;
    queue<Node *> q;
    queue<int> p;
    q.push(root);
    p.push(0);
    int level = 1;
    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
    
        int c_level = p.front();
        p.pop();        
    
        cout << curr -> key << " ";
    
        
        if(curr -> left != NULL){
            q.push(curr -> left);
            p.push(c_level + 1);
        }

        if(curr -> right != NULL){
            q.push(curr -> right);
            p.push(c_level + 1);
        }

        if(p.front() == level){
            cout<<endl;
            level++;
        }
    }

}

void line_by_line(Node *root){
    if(root == NULL) return;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        int count = q.size();
        for(int i = 0; i < count; i++){
            Node *curr = q.front();
            q.pop();
            cout << curr -> key <<" ";
            if(curr -> left != NULL)
                q.push(curr -> left);
            if(curr -> right != NULL)
                q.push(curr -> right);
        }
        cout<<endl;
    }
}

void line_by_line_different(Node *root){
    if(root == NULL) return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(q.size() > 1){

        Node *curr = q.front();
        q.pop();


        if(curr == NULL){
            cout<<"\n";
            q.push(NULL);
            continue;
        }

        cout << curr -> key << " ";

        if(curr -> left != NULL)
            q.push(curr -> left);
        if(curr -> right != NULL)
            q.push(curr -> right);

    }
}

int size_tree(Node *root){
    if(root == NULL)
        return 0;
     else 
        return size_tree(root -> left) + size_tree(root -> right) + 1;
    
}

int getSize_itr(Node *root){
    if(root == NULL) return 0;
    queue<Node *> q;
    q.push(root);
    int count = 1;
    while(!q.empty()){
        Node *curr = q.front();
        q.pop();

        if(curr -> left != NULL){
            q.push(curr -> left);
            count++;
        }
        if(curr -> right != NULL){
            q.push(curr -> right);
            count++;
        }
    }
    return count;
}

int getMax(Node *root){
    if(root == NULL)
        return INT_MIN;
    else
        return max(root -> key, max(getMax(root -> left), getMax(root -> right)));
}

void left_view_itr(Node *root){
    if(root == NULL) return;

    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
        int count = q.size();
        for(int i = 0; i < count; i++){
            Node *curr = q.front();
            q.pop();
            if(i == 0)
                cout << curr -> key << " ";
            
            if(curr -> left != NULL)
                q.push(curr -> left);
            if(curr -> right != NULL)
                q.push(curr -> right);
        }
    }
}

int maxLevel = 0;

void left_view(Node *root, int level){
    if(root == NULL){ return; }

    if(maxLevel < level){
        cout << root -> key << " ";
        maxLevel = level;
    }

    left_view(root -> left, level + 1);
    left_view(root -> right, level + 1);
}

bool childsum(Node *root){
    if(root == NULL) return true;

    if(root -> right == NULL && root -> left == NULL) return true;

    int left = 0, right = 0;
    if(root -> left != NULL)
        left = root -> left -> key;
    if(root -> right != NULL)
        right = root -> right -> key;

    return (root -> key == left + right) && childsum(root -> left) && childsum(root -> right);
}

int main(){
    
    // Node *root = NULL; -> An empty tree.
    // root -> left -> left = new Node(30);

    // Node *root = new Node(10);  
    // root -> left = new Node(20);
    // root -> right = new Node(30);
    // root -> left -> left = new Node(40);
    // root -> left -> right = new Node(50);
    // root -> right -> right = new Node(60);
    // root -> right -> right -> left = new Node(70);
    // root -> right -> right -> right = new Node(80);

    Node *root = new Node(30);
    root -> left = new Node(20);
    root -> right = new Node(50);
    root -> right -> left = new Node(60);
    root -> right -> left -> right = new Node(10);

    cout << ((childsum(root)) ? "YES" : "NO") << endl;

    // cout<<getMax(root)<<endl;
    return 0;
}

