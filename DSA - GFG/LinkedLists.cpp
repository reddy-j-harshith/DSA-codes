#include<bits/stdc++.h>

using namespace std;

struct Node{ 
    
    int data;
    Node* next;
    
    Node(int x){ // Constructor
        data = x;
        next = NULL;
    }

};

// Node with the visited attribute.
struct v_Node{ 
    int data;
    Node *next;
    bool visited;
    v_Node(int d){
        int data = d;
        next = NULL;
        visited = false;
    }
};


// To print the linked list.
void printLinkedList(Node* head){
    
    while(head != NULL){
        cout<<head -> data<<" ";
        head = head -> next; // Traversal
    }

}


// Insertion of a new Node at the beginning of the Linked List.
Node* insertBegin(Node* head, int x){
    
    Node* temp = new Node(x);
    temp -> next = head;
    return temp;

}

Node* insertAtEnd(Node* head, int x){
    
    Node* temp = new Node(x);

    if(head == NULL){ // When the Linked List is Empty. Just directly return the Temporary Node.
        return temp;
    }

    Node* curr = head;
    while(curr -> next != NULL){
        curr = curr -> next;
    }

    curr -> next = temp;
    return head;

}



Node* deleteFirstNode(Node* head){
    
    if(head == NULL) // When the Linked List is Empty.
        return NULL;

    else{
        Node* temp = head -> next;
        delete head;
        return temp;
    }

}



Node* deleteAtEnd(Node* head){

    if(head == NULL) // Corner case when the Linked List is empty.
        return NULL;
    
    if(head -> next == NULL){ // Corner case when there is only one element in the Linked List.
        delete head;          // Deleting the head pointer and returning an empty Linked List.
        return NULL;          // This is to prevent the segmentation fault when you access a NULL value.
    }

    Node* curr = head;
    while(curr -> next -> next != NULL){
        curr = curr -> next;
    }

    delete (curr -> next);
    curr -> next = NULL;
    return head;

}



Node* insertPos(Node* head, int pos, int data){ // In this implementation we need to assign the temp's next Node to the positions after it because in no doing so, we will lose track of the node after pos - 1.

    Node* temp = new Node(data);
    if(pos = 1){
        temp -> next = head;
        return temp;
    }

    Node* curr = head;
    for(int i = 1; i < pos - 1 && curr != NULL; i++)
        curr = curr -> next;

    if(curr == NULL)
        return head;

    temp -> next = curr -> next; // Handles both cases when the next node is NULL or an actual Node. temp Node's next is assigned to the next of the current.
    head -> next = temp; // Then the curr Node's next node (which is at a positon = pos - 1), is assigned to the new node.
    return head; // returning modified head pointer.

}



int searchLl(Node* head, int x){

    int pos = 1;
    Node* curr = head;
    while(curr != NULL){
        if(curr -> data == x)
            return pos;
        else{
            pos++;
            curr = curr -> next;
        }
    }
    return -1;

}



int searchLlRecursive(Node* node, int x){

    if(node == NULL) return -1;

    if(node -> data == x) return 1;
    else{
        int res = searchLlRecursive(node -> next, x);
        if(res == -1) return -1; // When the element x is not present in the Linked List.
        else          return 1 + res; // When the element is present in the Linked List.
    }

}




// Problems on Linked List;

Node *insert_in_sorted(Node *head, int data){
    Node* temp = new Node(data);
    if(head == NULL)
        return temp;
    
    if(head -> data > data){
        temp -> next = head;
        return temp;
    }

    Node *curr = head;
    while(curr -> next != NULL && curr -> next -> data < data ){
        curr = curr -> next;
    }

    temp -> next = curr -> next;
    curr -> next = temp;

    return head;
}



void printMiddle(Node *head){
    if(head == NULL)
        return;

    Node *slow = head, *fast = head;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    cout<<(slow -> data);

}



void printNthFromEnd(Node *head, int n){
    
    if(head == NULL)
        return;

    Node *first = head;
    for(int i = 0; i < n; i++){
        if(first == NULL) return; // To handle the case when K is more than the length of the Linked List.
        first = first -> next;
    }
    Node *second = head;

    while(first != NULL){
        first = first -> next;
        second = second -> next;
    }

    cout<<first -> data<<" ";
    
}



Node* reverseLinkedListExtraSpace(Node* head){

    if(head == NULL) return NULL;
    if(head -> next == NULL) return head;

    Node* curr = head -> next;
    Node* new_head = new Node(head -> data);
    while(curr != NULL){
        Node* temp = new Node(curr -> data);
        temp -> next = new_head;
        new_head = temp;

        curr = curr -> next;
    }
    delete head;
    return new_head;
}


// This better method is achieved by changing the direction of the links rather than creating a new linked list altogether.
Node *reverse_linked_list(Node *head){
    // No need for corner cases.
    
    Node *prev = NULL;
    Node *curr = head;

    while(curr != NULL){
        Node *next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}



Node* recursive_reverse(Node *head){

    if(head == NULL || head -> next == NULL) return head;

    Node *rest_head = recursive_reverse(head -> next); // Basically the head is traversing the linked list and at the final place where it reaches the base condition, it returns the final node.
    Node *rest_tail = head -> next;
    rest_tail -> next = head;
    head -> next = NULL;
    return rest_head; 
}


// Initially prev = NULL. This is similar to iterative solution.
Node *recursive_reverse2(Node *curr, Node *prev = NULL){

    if(curr == NULL) return prev;
    
    Node *next = curr -> next;
    curr -> next = prev;


    return recursive_reverse2(next, prev);
}


// Modifying the entire linked list connections.
Node *merge(Node *head1, Node *head2){

    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    
    Node *head = (head1 -> data < head2 -> data) ? (head1) : (head2);
    Node *tail = head;
    if(head == head1){
        head1 = head1 -> next;
    } else {
        head2 = head2 -> next;
    }

    while(head1 != NULL && head2 != NULL){

        if(head1 -> data <= head2 -> data){
            tail -> next = head1;
            head1 = head1 -> next;
        } else {
            tail -> next = head2;
            head2 = head2 -> next;
        }
        tail = tail -> next;
    }

    if(head1 == NULL)
        tail -> next = head2;
    else
        tail -> next = head1;
    return head;
}



Node *reverseKGroups(Node *head, int k){
    // if(head == NULL || head -> next == NULL) return head;

    Node *prev = NULL, *next = NULL;
    Node *curr = head;
    int i = 1;
    while(i < k && curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr; curr = next;
        i++;
    }
    if(next != NULL){
        Node *next_head = reverseKGroups(next, k); // To return the new head of the rest of the Linked List.
        head -> next = next; // Old head Linking to the new head of the next reversed group.
    }
    return prev; // New head of the Linked List
}


Node *reverseKthIterative(Node *head, int k){

    Node *curr = head, *prevFirst = NULL;
    bool isFirstPass = true;
    while(curr != NULL){
        Node *first = curr, *prev = NULL;
        int count = 0;
        while(count < k && curr != NULL){
            Node *next = curr -> next;
            curr -> next = prev;
            prev = curr; 
            curr = next;
            count++;
        }
        if(isFirstPass) { head = prev; isFirstPass = false; }
        else            { prevFirst -> next = prev; }
        prevFirst = first;
    }
    return head;
}


// Using the reverse linked list after a certain node and proceed with the checking.
bool palindrome_check(Node *head){
    if(head == NULL) return true;
    
    Node *slow = head, *fast = head;
    while(fast -> next != NULL && fast -> next -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    Node *new_head = reverse_linked_list(slow -> next);

    Node *curr = head;
    while(new_head != NULL){
        if(new_head -> data != curr -> data)
            return false;
        new_head = new_head -> next;
        curr = curr -> next;
    }
    return true;
}


// Floyd's loop checking algorithm
bool loop_check(Node *head){

    struct Node *slow = head, *fast = head;

    while(fast != NULL && fast -> next != NULL){
        
        slow = slow -> next;
        fast = fast -> next -> next;

        if(fast == slow)
            return true;
    }
    return false;
}

// Partially use the Floyd's loop checking algorithm to the get the first meeting point and the find the second meeting point.
Node *remove_loop(Node *head){
    Node *slow = head, *fast = head;
    while(fast -> next != NULL && fast -> next -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;

        if(fast == slow)
            break;
    }

    if(slow != fast)
        return head;
    
    slow = head;
    while(slow -> next != fast -> next){
        slow = slow -> next;
        fast = fast -> next;
    }

    fast -> next = NULL;
    return head;
}


// Assuming the node to be deleted is in the middle of the linked list.
void delete_random(Node *random_head){ 

    Node *temp = random_head -> next;
    random_head -> data = temp -> data;
    random_head -> next = temp -> next;
    delete(temp);

}


// separate the odd and even nodes with the even nodes being placed first and odd being placed later.
Node *segregate(Node *head){

    Node *eS = NULL, *eE = NULL, *oS = NULL, *oE = NULL;
    for(Node *curr = head; curr != NULL; curr = curr -> next){
        int x = curr -> data;
        if(x % 2 == 0){
            if(eS == NULL){
                eS = curr;
                eE = eS;
            } else {
                eE -> next = curr;
                eE = curr;
            }
        } else {
            if(oS == NULL){
                oS = curr;
                oE = oS;
            } else {
                oE -> next = curr;
                oE = curr;
            }
        }
    }

    if(eS == NULL || oS == NULL)
        return head;

    eE -> next = oS;
    oE -> next = NULL;
    return eS;
}


bool loop_check_visited(v_Node *head){
    v_Node *curr = head;
    while(curr != NULL){
        if(curr -> visited)
            return true;
    }
    return false;
}


// By check the loop using an auxiliary node.This method destroys the linked List entirely.
bool is_loop(Node *head){
    Node *temp = new Node(0);
    Node *curr = head;
    while(curr != NULL){

        if(head -> next == NULL)
            return false;
        if(head -> next = temp)
            return true; // The node is already pointing to the temp node.

        Node *next_curr = curr -> next;
        curr -> next = temp;
        curr = next_curr;
    }
    return false;
}



bool is_loop_hashing(Node *head){
    unordered_set<Node *> s;

    for(Node *curr = head; curr != NULL; curr = curr -> next){

        if(s.find(curr) != s.end())
            return true;
        s.insert(curr);
    }
    return false;
}


// This solution requires multiple traversals of the linked list.
int intersection_lists(Node *head1, Node *head2){

    int c1 = 1, c2 = 1;
    Node *curr1 = head1;
    while(curr1 != NULL){ // counting the number of elements in the first list
        curr1 = curr1 -> next;
        c1++;
    }

    Node *curr2 = head2;
    while(curr2 != NULL){ // counting the number of elements in the second list.
        curr2 = curr2 -> next;
        c2++;
    }

    int dif = abs(c1 - c2);

    curr1 = head1, curr2 = head2;

    if(max(c1, c2) == c1){ // traversing the starting point of the larger linked list.
        while(dif > 0){
            curr1 = curr1 -> next;
            dif--;
        }
    } else {
        while(dif > 0){
            curr2 = curr2 -> next;
            dif--;
        }
    }
    while(curr1 != NULL && curr2 != NULL){ // traversing both of the pointers until they meet after the buffer traversal.
        if(curr1 == curr2){ 
            return curr1 -> data;
        }   
        curr1 = curr1 -> next;
        curr2 = curr2 -> next;
    }
    return -1;
}



void pairwise_data_swap(Node *head){ // You are only swapping the data and this method is not universal and could only work with primitive types of data.
                                     // And this cannot work if you were to use it with objects or large amount of data moving which might be very costly.
    Node *curr = head;
    while(curr != NULL && curr -> next){
        swap(curr -> data, curr -> next -> data);
        curr = curr -> next -> next;
    }
}



Node *pairwise_swap(Node *head){

    if(head == NULL || head -> next == NULL) return head;

    Node *curr = head -> next -> next; // third node
    Node *prev = head; // first node
    head = head -> next; // move the first to the second node
    head -> next = prev; // links the second node to the first node and this same head will be returned to the origianl head variable.

    while(curr != NULL && curr -> next != NULL){
        
        prev -> next = curr -> next;
        prev = curr;
        Node *next = curr -> next -> next;
        curr -> next -> next = curr;
        curr = next;
    }
    prev -> next = curr;

    return head;
}



int main(){
    Node* head = NULL;
    head = insertBegin(head, 10);
    head = insertBegin(head, 27);
    head = insertBegin(head, 30);
    head = insertBegin(head, 13);
    head = insertBegin(head, 18);
    head = insertBegin(head, 91);
    head = insertBegin(head, 15);
    head = insertBegin(head, 20);
    head = insertBegin(head, 4);



    head = reverse_linked_list(head);
    head = segregate(head);
    printLinkedList(head);

}