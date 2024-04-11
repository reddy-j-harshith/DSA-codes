#include<bits/stdc++.h>

using namespace std;

int binarySearch(int* arr, int x, int lo, int hi){
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(arr[mid] < x)      lo = mid + 1;
        else if(arr[mid] > x) hi = mid - 1;
        else                  return mid;
    }
    return -1;
}

int distinctBSearch(int* arr, int n, int target){
    int lo = 0, hi = n - 1;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(arr[mid] > target)
            hi = mid - 1;
        else if(arr[mid] < target)
            lo = mid + 1;
        else{
            if(arr[mid] != arr[mid - 1] || mid == 0)
                return mid;
            else
                hi = mid - 1;
        }
    }
    return -1;
}

int distinctBSearchlast(int* arr, int n, int target){
    int lo = 0, hi = n - 1;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(arr[mid] > target)
            hi = mid - 1;
        else if(arr[mid] < target)
            lo = mid + 1;
        else{
            if(arr[mid] != arr[mid + 1] || mid == n - 1)
                return mid;
            else
                lo = mid + 1;
        }
    }
    return -1;
}

int binaryCountOcc(int* arr, int n, int x){
    return distinctBSearchlast(arr, n, x) - distinctBSearch(arr, n, x) + 1;
}


float sqRoot(float n){
    float lo = 0.0, hi = n;
    float epsilon = 0.000001;
    while(hi - lo > epsilon){
        float mid = lo + ((hi - lo) / 2.0);
        float square = mid * mid;
        if(square == n)     return mid;
        else if(square < n) lo = mid + epsilon;
        else                hi = mid - epsilon;
    }
    return lo + ((hi - lo) / 2.0);
}

int largeBSearch(int* arr, int n, int x){
    if(arr[0] == x) return 0;
    int i = 1;
    while(arr[i] < x)
        i *= 2;
    if(arr[i] == x) return i;

    return binarySearch(arr, x, i / 2 + 1, i - 1);
}


int thalaSearch(int* arr, int n, int x = 7){
    int lo = 0, hi = n - 1;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(arr[mid] == x) return mid + 1;
        if(arr[lo] < arr[mid]){
            if(x < arr[mid] && x > arr[lo])
                hi = mid - 1;
            else
                lo = mid + 1;
        } else {
            if(x > arr[mid] && x < arr[hi])
                lo = mid + 1;
            else
                hi = mid - 1;
        } 
    }
    return -1;
}

int findPeak(int* arr, int n){
    int lo = 0, hi = n - 1;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if((mid == 0 || arr[mid - 1] < arr[mid]) && 
            (arr[mid] > arr[mid + 1] || mid == n - 1)) return mid;
        if((arr[mid - 1] < arr[mid]) && mid > 0)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}


double getMedion(int* a1, int* a2, int n1, int n2){
    int begin1 = 0, end1 = n1 - 1;
    while(begin1 <= end1){
        int i1 = (begin1 + end1) / 2;
        int i2 = (n1 + n2 + 1) / 2 - i1;
        
        int max1 = (max1 == 0) ? (INT_MIN) : a1[i1 - 1];
        int max2 = (max2 == 0) ? (INT_MIN) : a2[i2 - 1];
        int min1 = (min1 == n1) ? (INT_MAX) : a1[i1];
        int min2 = (min2 == n2) ? (INT_MAX) : a2[i2];

        if(max1 <= min2 && max2 <= min1){
            if((n1 + n2) % 2 == 0)
                return (double)(max(max1, max2) + min(min1, min2));
            else
                return (double)max(max1, max2);
        } else if (max1 > min2) end1 = i1 - 1;
        else         begin1 = i1 + 1;

    }
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    
    cout<<findPeak(arr, n);
}