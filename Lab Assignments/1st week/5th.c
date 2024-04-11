#include <stdio.h>
#include <gmp.h>

int main() {
    mpz_t N, M, passcode;

    // Initialize variables
    mpz_init(N);
    mpz_init(M);
    mpz_init(passcode);

    // Read input numbers
    gmp_scanf("%Zd", N);
    gmp_scanf("%Zd", M);

    // Calculate the modular multiplicative inverse using mpz_invert
    mpz_invert(passcode, N, M);

    // Print the passcode
    gmp_printf("%Zd\n", passcode);

    // Clear variables
    mpz_clear(N);
    mpz_clear(M);
    mpz_clear(passcode);

    return 0;
}

