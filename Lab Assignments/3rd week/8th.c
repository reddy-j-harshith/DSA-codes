#include <stdio.h>

int countSetBits(unsigned long long num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    unsigned long long deals[n];
    for (int i = 0; i < n; i++) {
        scanf("%llu", &deals[i]);
    }

    int maxSatisfiedClients = 0;
    for (int i = 0; i <= n - k; i++) {
        unsigned long long satisfiedClients = 0;

        for (int j = i; j < i + k; j++) {
            satisfiedClients |= deals[j];
        }

        int count = countSetBits(satisfiedClients);

        if (count > maxSatisfiedClients) {
            maxSatisfiedClients = count;
        }
    }

    printf("%d\n", maxSatisfiedClients);

    return 0;
}
