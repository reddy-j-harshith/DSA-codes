#include <stdio.h>
#include <limits.h>
#define MAX_N 8
int min(int a, int b) {
    return (a < b) ? a : b;
} 

int max(int a, int b) {
    return (a > b) ? a : b;
}

int distributeMakeup(int packets[], int n, int k, int beauty[]) {
    if (n == 0) {
        int maxBeauty = INT_MIN;
        for (int i = 0; i < k; i++) {
        maxBeauty = max(maxBeauty, beauty[i]);
        }
         return maxBeauty;
    }
    int minBeauty = INT_MAX;
    for (int i = 0; i < k; i++) {
        beauty[i] += packets[n - 1];

    int currentMinBeauty = distributeMakeup(packets, n - 1, k, beauty);
    minBeauty = min(minBeauty, currentMinBeauty);
    beauty[i] -= packets[n - 1];
    }
    return minBeauty;
}


int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int packets[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &packets[i]);
    }
    int beauty[MAX_N] ={0}; // Initialize beauty of each person to 0
    int result = distributeMakeup(packets, n, k, beauty);
    printf("%d\n", result);
    return 0;
}