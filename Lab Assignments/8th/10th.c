#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int randomizedPartition(int arr[], int p, int r) {

    int random = p + rand() % (r - p + 1);
    swap(&arr[random], &arr[r]);

    int pivot = arr[r];
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (arr[j] >= pivot) { 
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}


int simplerRandomizedSelect(int arr[], int p, int r, int i) {
    if (p == r)
        return arr[p];
    int q = randomizedPartition(arr, p, r);
    int k = q - p + 1;
    if (i == k)
        return arr[q];
    else if (i < k)
        return simplerRandomizedSelect(arr, p, q - 1, i);
    else
        return simplerRandomizedSelect(arr, q + 1, r, i - k);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n,&k);
    int a[n];
  
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int kth_largest = simplerRandomizedSelect(a, 0, n - 1, k);

    printf("The %d-th largest element in the array is: %d\n", k, kth_largest);

    return 0;
}