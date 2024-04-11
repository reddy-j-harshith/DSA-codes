#include<stdio.h>
#include<string.h>

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

void stringLCM(char* a, char* b){
    int lengthA = strlen(a);
    int lengthB = strlen(b);
    int GCD = gcd(lengthA, lengthB);

    int maxLength = lengthA * lengthB / GCD;
    int max = (lengthA > lengthB) ? (lengthA) : (lengthB);

    if(strstr(a, b) != NULL || strstr(b, a) != NULL){
        while(maxLength > 0){
            printf("%s", a);
            maxLength = maxLength - lengthA;
        }

    } else {
        printf("-1");
        return;
    }


}

int main(){
    char a[1000001], b[1000001];
    scanf(" %s", a);
    scanf("%s", b);
    stringLCM(a, b);
}
    