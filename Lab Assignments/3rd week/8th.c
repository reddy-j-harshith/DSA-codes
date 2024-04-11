#include <stdio.h>

// Function to count the number of set bits (1s) in an integer
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
        // Initialize a bitmask to keep track of satisfied clients
        unsigned long long satisfiedClients = 0;

        // Iterate over the current segment of deals
        for (int j = i; j < i + k; j++) {
            // Update the bitmask by OR-ing the bits of each deal
            satisfiedClients |= deals[j];
        }

        // Count the number of set bits (satisfied clients) in the bitmask
        int count = countSetBits(satisfiedClients);

        // Update the maximum count of satisfied clients
        if (count > maxSatisfiedClients) {
            maxSatisfiedClients = count;
        }
    }

    printf("%d\n", maxSatisfiedClients);

    return 0;
}