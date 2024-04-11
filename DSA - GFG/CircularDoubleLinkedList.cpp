#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int x){
        data = x;
        prev = NULL;
        next = NULL;
    }
};


Node* insertBegin(Node* head, int data){

    Node* temp = new Node(data);
    if(head == NULL){
        temp -> prev = temp;
        temp -> next = temp;
        return temp;
    }
    temp -> prev = head -> prev;
    temp -> next = head;
    head -> prev -> next = temp;
    head -> prev = temp;

    return temp;

}



Node* insertEnd(Node* head, int data){

    Node* temp = new Node(data);
    if(head == NULL){
        temp -> prev = temp;
        temp -> next = temp;
        return temp;
    }
    temp -> prev = head -> prev;
    temp -> next = head;
    head -> prev -> next = temp;
    head -> prev = temp;

    return head;

}



int main(){



}