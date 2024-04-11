#include<bits/stdc++.h>

using namespace std;

struct FixedStack{
    int cap;
    int top;
    int *arr;

    FixedStack(int c){
        cap = c;
        arr = new int[cap];
        top = -1;
    }

    void push(int x){
        top++;
        arr[top] = x;
    }

    int pop(){
        int res = arr[top];
        top--;
        return res;
    }

    int peek(){
        return arr[top];
    }

    int size(){
        return top + 1;
    }

    bool isEmpty(){
        return top == -1;
    }
};

// Dyanimcally resized array
struct Stack{
    vector<int> v;
    
    void push(int x){
        v.push_back(x);
    }

    int pop(){
        int res = v.back();
        return res;
    }

    int size(){
        return v.size();
    }

    bool isEmpty(){
        return v.empty();
    }

    int peek(){
        return v.back();
    }
};

struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

struct Stackll{
    Node *top;
    int size;

    Stackll(){
        top = NULL;
        size = 0;
    }

    void push(int x){
        Node *temp = new Node(x);
        temp -> next = top;
        top = temp;
        size++;
    }
    
    int pop(){
        if(!isEmpty()){
            Node *temp = top;
            int element = top->data;
            top = temp -> next;
            delete(temp);
            size--;
            return element;
        } else 
            return INT_MAX;
    }

    bool isEmpty(){
        return size == 0;
    }

    int peek(){
        if(!isEmpty()){
            return top->data;
        }
        return INT_MAX;
    }
};

struct TwoStacks{
    int *arr;
    int cap;
    int top1, top2;
    TwoStacks(int n){
        cap = n;
        arr = new int[n];
        top1 = -1;
        top2 = cap;
    }

    
};

struct KStacks{
    int *arr, *next, *top;
    int cap, k1, freeTop;
    KStacks(int n, int k){
        cap = n;
        k1 = k;
        freeTop = 0;
        arr = new int[cap];
        next = new int[cap];
        top = new int[k];
        for(int i = 0; i < k; i++)
            top[i] = -1;

        for(int i = 0; i < cap - 1; i++)
            next[i] = i + 1;
        next[cap - 1] = -1;
    }

    void push(int sn, int x){
        if(freeTop != -1){
            int i = freeTop;
            freeTop = next[i];
            next[i] = top[sn];
            top[sn] = i;
            arr[i] = x;
        }
    }

    int pop(int sn){
        if(freeTop != 0){
            int i = top[sn];
            top[sn] = next[i];

            freeTop = i;
            
            return arr[i];
        }
    }
};

void printSpan(int *arr, int n){

    stack<int> s; // We are using this Stack to store the indexes of the stock prices.
    
    s.push(0);
    cout<<1<<" ";
    for(int i = 1; i < n; i++){
        while(s.empty() == false && arr[i] >= arr[s.top()])
            s.pop();
        int span = s.empty() ? i + 1 : i - s.top();
        cout<<span<<" ";
        s.push(i);
    }

}

void previousGreater(int *arr, int n){
    stack<int> s;

    cout<<-1<<" ";
    s.push(arr[0]);
    for(int i = 1; i < n; i++){
        while(s.empty() == false && s.top() >= arr[i])
            s.pop();
        
        int previous = s.empty() ? -1 : s.top();
        cout<<previous<<" ";
        s.push(arr[i]);
    }

}

void nextGreater(int *arr, int n){

    stack<int> s;
    s.push(arr[n - 1]);
    arr[n - 1] = -1;
    for(int i = n - 2; i >= 0; i--){
        while(s.empty() == false && s.top() <= arr[i])
            s.pop();

        int next = s.empty() ? -1 : s.top();
        s.push(arr[i]);
        arr[i] = next;

    }

    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";

}

int getMaxAreaNaive(int *arr, int n){
    int res = 0;
    for(int i = 0; i < n; i++){
        int curr = arr[i];

        for(int j = i - 1; j > 0 && arr[j] >= arr[i]; i--)
            curr += arr[j];

        for(int j = i + 1; j < n && arr[j] >= arr[i]; i++)
            curr += arr[j];
    
        res = max(res, curr);
    }
    return res;
}

vector<int> prevSmaller(int *arr, int n){

    stack<int> s;
    vector<int> vec;
    s.push(0);
    vec.push_back(-1);

    for(int i = 1; i < n; i++){
        while(s.empty() == false && arr[i] <= arr[s.top()])
            s.pop();

        int prev = s.empty() ? i : i - s.top() - 1;
        vec.push_back(prev);
        s.push(i);
    }
    return vec;
}

vector<int> nextSmaller(int *arr, int n){

    stack<int> s;
    vector<int> vec;
    s.push(n - 1);
    vec.push_back(-1);

    for(int i = n - 2; i >= 0; i--){
        while(s.empty() == false && arr[i] <= arr[s.top()])
            s.pop();

        int prev = s.empty() ? i : i - s.top() + 1;
        vec.push_back(prev);
        s.push(i);
    }
    return vec;
}


int main(){

    // stack<int> stk;
    // stk.push(10);
    // stk.push(20);
    // stk.push(30);

    // while(stk.empty() == false){
    //     cout<<stk.top()<<" ";
    //     stk.pop();
    // }

    // FixedStack s(5);

    // cout<<s.pop()<<endl;
    // cout<<s.peek()<<endl;
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    // s.push(50);
    // s.push(60);

    int arr[] = {5, 15, 10, 8, 6, 12, 9, 18};
    nextGreater(arr, 8);
    return 0;
}