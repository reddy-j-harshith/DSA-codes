#include<stdio.h>


int calculate(char num[]){
    int len= 0;
    while(num[len] != '\0')
        len++;
    return len;
}


void multiply(char num1[], char num2[], char result[]){
    int len1 = calculate(num1);
    int len2 = calculate(num2);
    int lenResult = len1 + len2;

    int product[lenResult];
    for(int i = 0 ; i < lenResult; i++)
    product[i] = 0;

    for(int i = len1 - 1; i >= 0; i--){
        for(int j = len2 - 1; j >= 0; j--){
        int digit1 = num1[i] - '0';
        int digit2 = num2[j] - '0';

        product[i + j + 1] += digit1 * digit2;

        if (product[i + j + 1] >= 10){
            product[i + j] += product[i + j + 1] / 10;
            product[i + j + 1] %= 10;
        }


        }
    }
    int index = 0;
    while(index < lenResult && product[index] == 0)
        index++;

    if(index == lenResult){
        result[0] = '0';
        result[1] = '\0';
        return;
    }
    
    int resultIndex = 0;
    while(index < lenResult){
        result[resultIndex++] = product[index] + '0';
        index++;
    }

    result[lenResult] = '\0';
}

void main(){
    char num1[1002], num2[1002], result[2005];

    scanf("%s", num1);
    scanf("%s", num2);

    multiply(num1, num2, result);

    printf("%s", result);
}