#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int key;
        int value;
        Node *prev;
        Node *next;

        Node(int k, int v){
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
};

class LRUCache{
    public:
        unordered_map<int, Node*> map;
        int capacity, count;
        Node *head, *tail;


        LRUCache(int c){
            capacity = c;
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head -> next = tail;
            tail -> prev = head;
            head -> prev = NULL;
            tail -> next = NULL;
            count = 0;
        }

        void delete_node(Node *node){
            node -> prev -> next = node -> next;
            node -> next -> prev = node -> prev;
        }

        void add_next_to_head(Node *node){
            node -> next = head -> next;
            node -> next -> prev = node;
            node -> prev = head;
            head -> next;
        }

        int get(int key){

            if(map[key] != NULL){
                Node *node = map[key];
                int result = node -> value;
                delete_node(node);
                add_next_to_head(node);
                cout<<"Got the value : "<<result<<" for the key "<<key<<endl;
                return result;
            }
            cout<<"Did not get any value for the key: "<<key<<endl;
            return -1;
        }

        void set(int key, int value){
            cout<<"Going to set the (key, value) : ("<<key<<", "<<value<<")"<<endl;
            if(map[key] != NULL){
                Node *node = map[key];
                node -> value = value;
                delete_node(node);
                add_next_to_head(node);
            } else {
                Node *node = new Node(key, value);
                map[key] = node;
                if(count < capacity){
                    count++;
                    add_next_to_head(node);
                } else {
                    map.erase(tail -> prev -> key);
                    delete_node(tail -> prev);
                    add_next_to_head(node);
                }
            }

        }
};

int main(){
    LRUCache cache(2);

    cache.set(1, 10);

    cache.set(2, 20);
	cout<<"Value for the key: 1 is... " << cache.get(1)<<endl; // returns 10 

    cache.set(3, 30);

    cout<<"Value for the key: 2 is... " <<cache.get(2)<<endl; // returns -1 (not found) 

    cache.set(4, 40);
    cout<<"Value for the key: 1 is... " << cache.get(1)<<endl; // returns -1 (not found) 
    cout<<"Value for the key: 3 is... " << cache.get(3)<<endl; // returns 30 
    cout<<"Value for the key: 4 is... " << cache.get(4)<<endl; // return 40 
                    
	return 0;
}