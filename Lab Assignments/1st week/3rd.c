#include <stdio.h>
#include <gmp.h>

int main(){
    mpz_t num1,num2,result;
    mpz_init(num1);
    mpz_init(num2);
    mpz_init(result);
    
    gmp_scanf("%Zd",num1);
    gmp_scanf("%Zd",num2);
    
    mpz_mul(result,num1,num2);
    
    gmp_printf("%Zd\n",result);
    
    mpz_clear(num1);
    mpz_clear(num2);
    mpz_clear(result);
    
    return 0;
}