#include <stdio.h>
#include <math.h>

unsigned long long int split(unsigned long long int l,char n1[],char n2[])
{
    char a[1000];
    char b[1000];
    char c[1000];
    char d[1000];

    unsigned long long int prod1 = 0, prod2 = 0, prod3 = 0, prod4 = 0, sum = 0, i;

    
    if(l == 1)
    {
        return ((n1[0] - '0') * (n2[0] - '0'));
    }

    unsigned long long int k = 0, p = 0;
    for(i = 0 ; i < l ; i++) {
        if(i < l/2)
        {
            a[p] = n1[i];
            c[p] = n2[i];
            p++;
        }
        else {
            b[k] = n1[i];
            d[k] = n2[i];
            k++;
        }
    }
    a[p] = '\0';
    b[k] = '\0';
    c[p] = '\0';
    d[k] = '\0';
    prod1 = split(l/2,a,c);
    prod2 = split(l/2,b,d);
    prod3 = split(l/2,a,d);
    prod4 = split(l/2,b,c);
    sum = prod3 + prod4;

    return (prod1 * pow(10,l) + sum * pow(10,l/2) + prod2);
}


int main() {
   
   char x[1024];
   char y[1024];
   
   scanf("%s", x);
   scanf("%s", y);

   unsigned long long int l1 = 0, l2 = 0;
   while(x[l1] != '\0') {
        l1++;
   }
   l2=l1;
   
   unsigned long long int s = split(l1, x, y);
   printf("%lld", s);
   return 0;
}