#include<bits/stdc++.h>

using namespace std;

struct Point{
    int x;
    int y;
};


// New comparator for STL containers
bool myComp(Point A, Point B){
    return A.x <= B.y;
}


// BUBBLE SORT

void bubble_sort(int arr[], int n){

    for(int i = 0; i < n - 1; i++){
        bool swap_detect = false;
        for(int j = 0; j < n - j - 1; j++){
            if(arr[j] < arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                swap_detect = true;
            }
        }
        if(!swap_detect){
            break;
        }
    }
}


//SELECTION SORT

void selection_sort(int *arr, int n){

    for(int i = 0; i < n - 1; i++){
        int minimum_index = i;
        for(int j = i + 1; j < n; j++){
            if(arr[minimum_index] > arr[j])
                minimum_index = j;
        }
        swap(arr[minimum_index], arr[i]);
    }

}


//INSERTION SORT

// Based on swapping.
void insertion_sort_swapping(int *arr, int n){

    for(int i = 1; i < n; i++){
        int temp = arr[i];
        for(int j = i; j > 0; j--){
            if(temp < arr[j - 1])
                swap(arr[j - 1], arr[j]);
            else
                break;
        }

    }

}

// Based on the shifting of the values in the arrays.
void insertion_sort(int *arr, int n){
    for(int i = 1; i < n; i++){
        int key = arr[i]; // store the value of arr[i].
        int j = i - 1;
        while(j >= 0 && key < arr[j]){ // finds the position of the new value to be inserted.
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


//MERGE SORT
void merge_two_arrays(int *arr1, int *arr2, int n1, int n2){
    int i = 0, j = 0;
    while(i != n1 && j != n2){
        if(arr1[i] < arr2[j]){
            cout<<arr1[i]<<" ";
            i++;
        } else {
            cout<<arr2[j]<<" ";
            j++;
        }
    }

    // To ensure the printing of left-out elements.
    while(i < n1){ cout<<arr1[i]<<" "; i++;}
    while(j < n2){ cout<<arr2[j]<<" "; j++;}

}

int count_inv = 0;
void merge(int *arr, int low, int mid, int high){

    int n1 = mid - low + 1, n2 = high - mid;
    int left[n1], right[n2];
    for(int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for(int i = 0; i < n2; i++)
        right[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = low;
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++]; count_inv += (n1) - i;
        }
    }
    while(i < n1){
        arr[k++] = left[i++]; 
    }
    while(j < n2){
        arr[k++] = right[j++];
    }

}


void merge_sort(int *arr, int low, int high){
    if(low < high) { // Atleast 2 elements should be present to continue.
        int mid = low + (high - low) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}



void sort_intersection(int *a, int *b, int n, int m){

    int i = 0, j = 0;
    while(i < n && j < m){
        if(i > 0 && a[i] == a[i - 1]){ i++; continue; }
        if(j > 0 && b[j] == b[j - 1]){ j++; continue; }
        if(a[i] < b[j]){ cout<<a[i]<<" "; i++; }
        else if(a[i] > b[j]){ cout<<b[j]<<" "; j++; }
        else{
            cout<<a[i]<<" ";
            i++; j++;
        }
    }

    while(i < n)
        if(i > 0 && a[i] != a[i - 1]) { cout<<a[i]<<" "; i++; }
    while(j < m)
        if(j > 0 && b[j] != b[j - 1]) cout<<b[j]<<" ";
}


void sort_union(int *a, int *b, int n, int m){
    int i = 0, j = 0;
    while(i < n && j < m){
        if(i > 0 && a[i] == a[i - 1]){ i++; continue; }
        if(j > 0 && b[j] == b[j - 1]){ j++; continue; }
        if(a[i] < b[j]) { cout<<a[i]<<" "; i++; }
        else if(a[i] > b[j]) { cout<<b[j]<<" "; j++; }
        else { cout<<a[i]<<" "; i++; j++; }
    }

    while(i < n){
        if(i > 0 && a[i] != a[i - 1]) 
           { cout<<a[i]<<" "; }
        i++;
    }
    
    while(j < m) 
        if(j > 0 && b[j] && b[j - 1])
           { cout<<b[j]<<" "; }
        j++;
}


int countMergeInversions(int *arr, int low, int mid, int high){
    int n1 = mid - low + 1, n2 = high - mid;
    int left[n1], right[n2];
    for(int i = 0; i < n1; i++) left[i] = arr[low + i];
    for(int i = 0; i < n2; i++) right[i] = arr[mid + i + 1];

    int res = 0, i = 0, j = 0, k = low;
    while(i < n1 && j < n2){
        if(left[i] <= right[j]) arr[k] = left[i++];
        else                   { arr[k] = right[j++]; res += n1 - i; }
        k++;
    }

    while(i < n1) arr[k++] = left[i++];
    while(j < n2) arr[k++] = right[j++];
    return res;
}


int mergeSortInversions(int *arr, int low, int high){
    int res = 0;
    if(low < high){
        int mid = low + (high - low) / 2;
        res += mergeSortInversions(arr, low, mid);
        res += mergeSortInversions(arr, mid + 1, high);
        res += countMergeInversions(arr, low, mid, high);
    }
    return res;
}


int partition(int *arr, int low, int high){
    int pivot = arr[low];
    int left = low, right = high;
    while(left < right){
        while(arr[left] <= pivot) left++;
        while(arr[right] > pivot) right--;
        if(left < right) swap(arr[left], arr[right]);
    }

    arr[low] = arr[right];
    arr[right] = pivot;
    return right;
}


void quick_sort(int *arr, int low, int high){
    if(low <= high){
        int pivot = partition(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}


void cycle_sort(int *arr, int n){

    int item = arr[0];
    for(int i = 0 ; i < n - 1;){
        int count = 0;
        for(int j = i + 1   ; j < n; j++){
            if(arr[j] <= arr[i]){
                count++;
            }
        }
        if(count == 0){
            i++;
        }
        else{
            arr[i +count] = item;
            arr[i + count] = arr[i];
            item = arr[i];
        }
    }
}



int main(){

    // Point arr[] = {{3, 10}, {2, 8}, {4, 10}, {2, 13}};
    // sort(arr, arr + 4, myComp);

    int arr[] = {80, 40, 30, 60, 20, 40, 10, 70, 90, 25};
    int arr1[] = {1, 20, 20, 20};
    int arr2[] = {20, 40, 50, 10, 30};
    // insertion_sort(arr, 7);
    // insertion_sort(arr1, 5);
    // merge_two_arrays(arr, arr1, 5, 9);

    // merge_sort(arr1, 0, 4);

    // for(auto element : arr1){
    //     cout<<element<<" ";
    // }
    // cout<<count_inv<<" ";
    // sort_union(arr, arr1, 8, 4);

    quick_sort(arr, 0, 9);
    for(auto i : arr){
        cout<<i<<" ";
    }
}