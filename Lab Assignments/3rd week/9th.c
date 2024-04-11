#include <stdio.h>
#include <stdbool.h>

#define MOD 1000000007

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

// Function to find the product of all non-prime numbers in the array modulo MOD
long long product_of_non_primes(int arr[], int n) {
    long long product = 1;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (!is_prime(arr[i])) {
            product = (product * arr[i]) % MOD;
            found = true;
        }
    }
    return found ? product : -1;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Output
    printf("%lld\n", product_of_non_primes(arr, n));

    return 0;
}