#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

typedef struct{
    int index;
    int value;
} Element;

int max(int a, int b){
    return a > b ? a : b;
}

void couting_sort(Element *input, int n, int k){

    int count[k];
    for(int i = 0 ;i < k; i++)
        count[i] = 0;
    for(int i = 0; i < n; i++)  
        count[input[i].value]++;

    for(int i = 1; i < k; i++)
        count[i] = count[i] + count[i - 1];

    Element *output = (Element *)malloc(n * sizeof(Element));
    for(int i = n - 1; i >= 0; i--){
        output[count[input[i].value] - 1] = input[i];
        count[input[i].value]--;
    }

    for(int i = 0 ;i < n; i++){
        input[i] = output[i];
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n], k = INT_MIN;
    for(int i = 0 ; i < n ;i++){
        scanf("%d", &arr[i]);
        k = max(k, arr[i]);
    }

    Element input[n];
    for(int i = 0; i < n; i++){
        input[i].value = arr[i];
        input[i].index = i;
    }

    couting_sort(input, n, k + 1);

    for(int i = 0; i < n; i++)
        printf("%d ", input[i].value);
    printf("\n");
    for(int i = 0; i < n; i++)
        printf("%d ", input[i].index + 1);

}