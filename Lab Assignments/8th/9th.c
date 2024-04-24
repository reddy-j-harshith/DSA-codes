#include <stdio.h>
#include <stdlib.h>
int SWAP(int a,int b) { int temp = a; a = b; b = temp; }


int partition(int arr[], int left, int right, int pivot) {
    int i = left - 1; 
    for (int j = left; j < right; j++) {
        if (arr[j] > pivot) {
            i++;
            SWAP(arr[i], arr[j]);
        }
    }
    SWAP(arr[i + 1], arr[right]);
    return i + 1;
}

int medianOf5(int arr[], int left, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[left + j] > arr[left + j + 1]) {
                SWAP(arr[left + j], arr[left + j + 1]);
            }
        }
    }
    return arr[left + n / 2];
}
int findMedian(int arr[], int left, int right) {
    int n = right - left + 1; 

    int i, median[(n + 4) / 5];
    for (i = 0; i < n / 5; i++) {
        median[i] = medianOf5(arr, left + i * 5, 5);
    }
    if (i * 5 < n) {
        median[i] = medianOf5(arr, left + i * 5, n % 5);
        i++;
    }
    return (i == 1) ? median[i - 1] : findMedian(median, 0, i - 1);
}

int selectKthLargest(int arr[], int left, int right, int k) {
    int pivot = findMedian(arr, left, right);

    int pos = partition(arr, left, right, pivot);

    if (pos - left == k - 1)
        return arr[pos];
    else if (pos - left < k - 1)
        return selectKthLargest(arr, pos + 1, right, k - pos + left - 1);
    else
        return selectKthLargest(arr, left, pos - 1, k);
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int kthLargest = selectKthLargest(arr, 0, n - 1, k);
    printf("%d\n", kthLargest);
    return 0;
}