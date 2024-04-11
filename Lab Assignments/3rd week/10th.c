#include <stdio.h>

#define MOD 1000000007

int main() {
    int n;
    scanf("%d", &n);

    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    long long product = 1;
    for (int i = 0; i < n; i++) {
        // Perform exponentiation by repeated squaring
        long long base = a[i];
        int power = b[i];
        long long result = 1;
        while (power > 0) {
            if (power % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;  //when power%2==0 then base is multiplied by itself making the required product but in time complexity of O(logn)
            power /= 2;
        }
        product = (product * result) % MOD;
    }

    printf("%lld\n", product);

    return 0;
}