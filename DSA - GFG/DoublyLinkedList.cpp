#include<bits/stdc++.h>

using namespace std;


struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};



void printDLL(Node* head){
    Node* curr = head;
    while(curr != NULL){
        cout<<curr -> data<<" ";
        curr = curr -> next;
    }
}



Node* insertBegin(Node* head, int x){

    Node* temp = new Node(x);
    temp -> next = head;
    if(head != NULL)
        head -> prev = temp;
    return temp;

}



Node* insertEnd(Node* head, int data){

    Node* temp = new Node(data);
     if(head == NULL)
        return temp;
    Node* curr = head;
    while(curr -> next = NULL)
        curr = curr -> next;
    curr -> next = temp;
    temp -> prev = curr;
    return head;

}



Node* reverseDLL(Node* head){

    if(head == NULL || head -> next == NULL)
        return head;


    Node *tempPrev = NULL, *curr = head;
    while(curr != NULL){
        tempPrev = curr -> prev;
        curr -> prev = curr -> next;
        curr -> next = tempPrev;

        curr = curr -> prev;
    }
    return tempPrev -> prev;

}

Node* deleteHeadDLL(Node* head){
    if(head == NULL)
        return NULL;
    if(head -> next == NULL){
        delete head; // Momery deallocation of the head variable.
        return NULL;
    }
    else{
        Node* temp = head;
        head = head -> next;
        head -> prev = NULL;
        delete temp;
        return head;
    }
}



Node* deletelastDLL(Node *head){
    if(head == NULL)
        return NULL;

    if(head -> next == NULL){
        delete head;
        return NULL;
    }
    else{
        Node *curr = head;
        while(curr -> next != NULL){
            curr = curr -> next;
        }
        curr -> prev -> next = NULL;
        delete curr;
        return head;
    }
}



int main(){
    
    Node* head = new Node(10);
    head = insertBegin(head, 20);
    head = insertBegin(head, 30);
    head = insertBegin(head, 40);
    head = insertBegin(head, 50);

    head = reverseDLL(head);

    printDLL(head);
}