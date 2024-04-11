#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node (int x){
        data = x;
        next = NULL;
    }
};



void printCLL(Node* head){
    if(head == NULL) return;
    cout<<(head -> data)<<" "; // required for single node case.
    for(Node *curr = head -> next; curr != head; curr = curr -> next)
        cout<<curr -> data<<" ";
}



void printCLLBetter(Node *head){

    if(head == NULL) return;
    Node *p = head;
    do{
        cout<<p -> data<<" ";
        p = p -> next;
    } while (p != head);

}



Node* insertBegin(Node* head, int data){
    Node* temp = new Node(data);
    if(head == NULL){
        temp -> next = temp;
    } else {
        Node* curr = head;
        while(curr -> next != head)
            curr = curr -> next;

        curr -> next = temp;
        temp -> next = head;
    }
    return temp;
}



Node* insertBeginBetter(Node* head, int data){

    Node* temp = new Node(data);
    if(head == NULL){
        temp -> next = temp;
        return temp;
    } else {
        temp -> next = head -> next;
        head -> next = temp;

        swap(temp -> data, head -> data);
        return head;
    }

}



Node* insertEnd(Node* head, int data){

    Node* temp = new Node(data);
    if(head == NULL){
        temp -> next = temp;
    } else {
        temp -> next = head -> next;
        head -> next = temp;

        swap(temp -> data, head -> data);
    }
    return temp;
}



Node *deleteHead(Node* head){
    if(head == NULL)
        return NULL;
    if(head -> next == NULL){
        delete head;
        return NULL;
    }
    head -> data = head -> next -> data;
    Node* temp = head -> next;
    head -> next = head -> next -> next;
    delete temp;
    return head;
}



int main(){

    Node *head = new Node(10);
    insertBeginBetter(head, 20);
    insertBeginBetter(head, 30);
    insertBeginBetter(head, 40);
    insertBeginBetter(head, 50);
    insertBeginBetter(head, 60);
    insertBeginBetter(head, 70);

    insertEnd(head, 35);

    printCLLBetter(head);

}