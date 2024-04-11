#include<bits/stdc++.h>

using namespace std;

class MinHeap{
    int *arr;
    int size;
    int capacity;

    public:        
        MinHeap(int c){
            arr = new int[c];
            size = 0;
            capacity = c;
        }

    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int parent(int i) { return (i - 1) / 2; }


    // inserting a new value in the minHeap
    void insert(int x){
        if(size == capacity) return;

        size++; arr[size - 1] = x;

        for(int i = size - 1; i != 0 && arr[parent(i)] > arr[i]; ){
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }


    // This function is to check only if the root of heap is not obeying the heap condition.
    // But we can call this function from any node violating the heap condtion assuming the node as the root of the heap there on.
    void min_heapify(int i){

        int left_child = left(i), right_child = right(i);
        int smallest = i;

        if(left_child < size && arr[left_child] < arr[i]) // checking the existence of left child and comparing.
            smallest = left_child;
        if(right_child < size && arr[right_child] < arr[i]) // checking the existence of right child and comparing. 
            smallest = right_child;
        if(smallest != i){
            swap(arr[i], arr[smallest]);
            min_heapify(i); // recursive call to the next sutree.
        }

    }



    int extract_min(){

        if(size == 0)
            return INT_MAX;
        if(size == 1){ // To prevent calling the minHeapify function for zero elements.
            size--;
            return arr[0];
        }
        swap(arr[0], arr[size - 1]);
        size--;
        MinHeap(0);
        return arr[size];
    }

    void siftup(int i){

        while(i != 0 && arr[i] > arr[parent(i)]){
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }

    }

    void decrease(int i, int x){
        if(i >= size) return;
        arr[i] = x;
        siftup(i);
    }

    void deleteKey(int i){
        decrease(i, INT_MIN);
        extract_min();
    }

    void buildHeap(){

        for(int i = (size - 2) / 2; i >= 0; i--){
            min_heapify(i);
        }

    }
};


