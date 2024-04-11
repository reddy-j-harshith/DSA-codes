#include <stdio.h>

// void calculateHighest(char* number, int n, int k){
//     if(n == 1 && k == 0) {
//         printf("0");
//     } else if(k == 0) {
//         printf("-1");
//     } else {
//         for(int i = 0; i < n; i++){
//             int temp = 9;
//             while(k > 0){
//                 if(k - temp >= 0){
//                     number[i] = temp + '0';
//                     k -= temp;
//                     break;
//                 } else {
//                     temp--;
//                 }
//             }
//         }

//         for(int i = 0; i < n; i++){
//             printf("%c", number[i]);
//         }
//     }
// }

void calculateLowest(char* num, int n, int k){
    if(n == 1 && k == 0) {
        printf("0");
    } else if(k == 0) {
        printf("-1");
    } else {
        char* number = num;
        number[0] = '1';
        k--;

        for(int i = n - 1; i >= 0; i--){
            int temp = 9;
            while(k > 0){
                if(k - temp >= 0){
                    
                    number[i] = temp + '0';
                    k -= temp;
                    break;
                } else {
                    temp--;
                }
            }
        }

        number[n] = '\0'; // Add null terminator

        printf("%s", number);
    }
}

void calculateHighest(char* num, int n, int sum){
    if(sum == 0 && n == 1) printf("0");
    else if(sum == 0)      printf("-1");
    else if(n * 9 < sum)   printf("-1");
    else{
        char* number = num;
        for(int i = 0; i < n; i++){
            int temp = 9;
            while(sum > 0){
                if(sum - temp >= 0){
                    number[i] = temp + '0';
                    sum -= temp;
                    break;
                } else {
                    temp--;
                } 
            }
        }
        number[n] = '\0';
        for(int i = 0; i < n; i++)
            printf("%c", number[i]);
    }
}

// void calculateLowest(char* num, int n, int sum){
//     if(sum == 0 && n == 1) printf("0");
//     else if(sum == 0)      printf("-1");
//     else if(n * 9 < sum)   printf("-1");
//     else{
//         char* number = num;

//         number[0] = '1';
//         sum--;

//         for(int i = n - 1; i >= 0; i++){
//             int temp = 9;
//             while(sum > 0){
//                 if(sum > 0){
//                     number[i] = temp + '0';
//                     break;
//                 }else{
//                     temp--;
//                 }
//             }
//         }
//         number[n] = '\0';
//         for(int i = 0; i < n; i++)
//             printf("%c", number[i]);

//     }
// }

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char number[n];

    for(int i = 0; i < n; i++)
        number[i] = '0';

    calculateLowest(number, n, k);
    printf(" ");
    calculateHighest(number, n, k);

    return 0;
}
