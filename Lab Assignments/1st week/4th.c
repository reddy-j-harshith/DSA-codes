#include <stdio.h>
#include <gmp.h>

int countSetBits(mpz_t num) {
    int count = 0;
    
    // Count the number of set bits in the binary representation
    while (mpz_cmp_ui(num, 0) > 0) {
        count += mpz_tstbit(num, 0);
        mpz_fdiv_q_2exp(num, num, 1);  // Right shift by 1
    }

    return count;
}

int main() {
    // Initialize GMP integer
    mpz_t num;
    mpz_init(num);

    // Input
    gmp_scanf("%Zd", num);

    // Count the number of set bits
    int result = countSetBits(num);

    // Output
    printf("%d\n", result);

    // Free GMP integer
    mpz_clear(num);

    return 0;
}