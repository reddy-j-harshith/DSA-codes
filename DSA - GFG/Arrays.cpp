#include<bits/stdc++.h>

using namespace std;

int secondLargest(vector<int> arr){
    int res = -1;
    int Largest = 0;
    for(int i = 1 ; i < arr.size(); i++){
        if(arr[Largest] < arr[i]){
            arr[res] = arr[Largest];
                Largest = i;
        } else if(arr[Largest] == arr[i]) {
            continue;
        } else if(arr[Largest] > arr[i]) {
            if(res == -1 || arr[i] < arr[res])
                res = i;
            else if(arr[res] >= arr[i])
                continue;
        }
    }
    return res;
}

void swap(int& a, int& b){
    int temp = b;
    b = a;
    a = temp;
}

void reverseArray(int* arr, int n){
    for(int i = 0; i < n >> 1; i++)
        swap(arr[i], arr[n - i - 1]);
}

void reverseArrayB(int* arr, int lo, int hi){
    while(lo < hi){
        int temp = arr[lo];
        arr[lo] = arr[hi];
        arr[hi] = temp;

        lo++;
        hi--;
    }
}

void reverse(int* arr, int lo, int hi){
    while(lo < hi){
        swap(arr[lo], arr[hi]);
        lo++; hi--;
    }
}

int removeDups(int* arr, int n){
    int res = 1;
    for(int i = 0; i < n ; i++){
        if(arr[i] != arr[res - 1]){
            arr[res] = arr[i];
            res++;
        }
    }
    return res;

}

 void moveZeros(int* arr, int n){
    int count = 0;
    for(int i = 0; i < n - 1; i++){
        if(arr[i] != 0){
            count++;
        }
    }
}

void leftRotD(int* arr, int n, int d){

    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);

}

void leaders(int* arr, int n){
    int max = arr[n - 1];
    cout<<arr[n - 1]<<" ";
    for(int i = n - 2; i >= 0; i--){
        if(arr[i] > max){
            max = arr[i];
            cout<<max<<" ";
        }
    }
}

int maxDiff(int* arr, int n){
    int res = arr[1] - arr[0];
    int min = arr[0];
    for(int i = 1 ; i < n ; i++){
        if(arr[i] - min > res) res = arr[i] - min;
        if(arr[i] < min) min = arr[i];
    }
    return res;
}

void frequencies(int* arr, int n){
    int count = 1;
    for(int i = 0 ; i < n; i ++){
        if(arr[i] == arr[i + 1]) count++;
        else{
            cout<<arr[i]<<" "<<count<<endl;
            count = 1;
        }
    }   
}


int maxProfit(int* arr, int n){
    int sum = 0;
    for(int i = 0; i < n - 1 ; i++)
        if(arr[i] <= arr[i + 1]) sum += arr[i + 1] - arr[i];
    return sum;
}

int waterTrap(int* arr, int n){
    int res = 0;
    int lMax[n], rMax[n];
    lMax[0] = arr[0], rMax[n - 1] = arr[n - 1];
    for(int i = 1; i < n; i++)
        lMax[i] = max(lMax[i - 1], arr[i]);

    for(int i = n - 2; i >= 0; i--)
        rMax[i] = max(rMax[i + 1], arr[i]);

    for(int i = 1; i < n - 1; i++)
        res = res + min(lMax[i], rMax[i]) - arr[i];
    return res;
}


int maxOnes(int* arr, int n){
    int count = 0;
    int maxCount = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 1) count++;
        if (arr[i] == 0 || i == n - 1){
            maxCount = max(maxCount, count);
            count = 0;
        }
    }
    return maxCount;
}

int Kadane(int* arr, int n){
    int maxEndingHere = arr[0];
    int maxSoFar = arr[0];
    for(int i = 1; i < n; i++){
        maxSoFar = max(maxSoFar + arr[i], arr[i]);
        maxEndingHere = max(maxEndingHere, maxSoFar);
    }
    return maxEndingHere;
}
int minKadane(int* arr, int n){
    int minEndingHere = arr[0];
    int minEndingSoFar = arr[0];
    for(int i = 1; i < n; i++){
        minEndingSoFar = min(minEndingSoFar + arr[i], arr[i]);
        minEndingHere = min(minEndingHere, minEndingSoFar);
    }
    return minEndingHere;
}

int  maxEvenOdd(int* arr, int n){
    int maxCount = 0, count = 1, temp = arr[0] % 2;
    for(int i = 1 ; i < n ; i++){
        if(temp != arr[i] % 2){
            count++;
        }
        else{
            count = 1;
        }
        temp = arr[i] % 2;
        maxCount = max(maxCount, count);
    }
    return maxCount;
}


int maxSliding(int* arr, int n, int k = 3){
    int sum = 0;
    for(int i = 0; i < k; i++)
        sum += arr[i];

    int maxSum = sum;    

    for(int i = k; i < n; i++){
        sum += arr[i] - arr[i - k];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

bool isSubSum(int* arr, int n, int k){
    int windowSum = 0, left = 0;
    for(int right = 0; right < n; right++){
        while(windowSum > k){
            windowSum -= arr[left];
            left++;
        }
        if(windowSum < k) windowSum += arr[right];
        if(windowSum == k) return true;
    }
    return false;
}

void mN_Bonacci(int n, int m){
    int windowSum = 0, left = 0;
    int arr[m]; arr[0] = 0;
    for(int i = 1; i < n; i++){
        arr[i] = (i == n - 1) ? (1) : (0);
        windowSum += arr[i];
        cout<<arr[i]<<" ";
    }
    for(int right = n; right < m; right++){
        arr[right] = windowSum;
        windowSum += arr[right] - arr[left];
        if(right >= n)
            left++;
        cout<<arr[right]<<" ";
    }
}

int maxCircularSum(int* arr, int n){
    int maxNormal = Kadane(arr, n); // Max of Normal Subarrays
    int minNormal = minKadane(arr, n);
    int sumArr = 0;
    if(maxNormal < 0) return maxNormal;
    for(int i = 0; i < n; i++)
        sumArr += arr[i];
    int maxCircular = sumArr - minNormal;
    return max(maxNormal, maxCircular);
}

int majorityElement(int* arr, int n){
    int count = 1, res = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] == arr[res])
            count++;
        else
            count--;
        if(count == 0){ res = i; count = 1;}
    }
    count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == arr[res]) count++;
    }
    return (count > n / 2) ? (arr[res]) : (-1);
}


void min_group_flips(int* arr, int n){
    int res = (arr[0] == 0) ? 1 : 0;
    int left = 0;
    for(int right = 0; right < n; right++){
        if(arr[left] != res) left = right;
        else if(arr[right] != res && left != right){
            cout<<"From "<<left<<" to "<<right - 1<<endl;
            left = right;
        }
    }
}

int lsumsrum(int* arr, int n){
    int rsum = 0;
    for(int i = 1 ; i < n; i++)
        rsum += arr[i];
    int lsum = 0;
    for(int i = 0; i <= n - 1 ; i++){
        if(lsum == rsum) return arr[i];
        else {
            lsum += arr[i];
            rsum -= arr[i + 1];
        }
    }
    return -1;
}


int maxOcc(int* L, int* R, int n){
    vector<int> arr(1000);
    for(int i = 0; i < n ; i++){
        arr[L[i]]++;
        arr[R[i] + 1]--;
    }

    int maxm = 0, res = 0;

    for(int i = 0; i < 1000;i++){
        arr[i] += arr[i - 1];
        if(maxm < arr[i]) {maxm = arr[i]; res = i;}
    }
    return maxm;
}

int gcd(int a, int b){
    if(b == 0)  return a;
    return gcd(b, a % b);
}

int sum(int* arr, int lo, int hi){
    int s = 0;
    for(int i = lo; i <= hi; i++)
        s += arr[i];
    return s;
}

int minimumPages(int *arr, int n, int k){
    if(k == 1) return sum(arr, 0, n - 1);
    if(n == 1) return 1;
    int res = INT_MAX;
    for(int i = 0; i < n; i++)
        res = min(res, max(minimumPages(arr, i, k - 1), sum(arr, i, n - 1)));
    return res;    
}

int minimumPagesBinary(int* arr, int n, int k){
    int hi = 0;
    int lo = INT_MIN;
    for(int i = 0; i < n; i++){
        hi += arr[i];
        lo = max(lo, arr[i]);
    }

    while(lo < hi){
        int mid = lo + (hi - lo) / 2, count = 1, temp = 0;
        for(int i = 0; i < n; i++){
            temp += arr[i];
            if(temp > mid){
                count++;
                temp = arr[i];
            }
        }
        if(count > k){
            lo = mid + 1;
        }
        else
            hi = mid - 1;
        
    }
    return (hi + lo) / 2;
}


int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i = 0; i < n ; i++){
        cin>>arr[i];
    }   

    cout<<minimumPagesBinary(arr, n, k);
}