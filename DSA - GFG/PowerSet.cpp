#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

void printPowerSet(string str){
    int n = str.length();
    int powSize = pow(2, n);
    for(int counter = 0; counter < powSize; counter++){
        for(int i = 0; i < n; i++){
            if((counter & (1 << i)) != 0){
                printf("%c", str[i]);
            }
        } printf("\n");
    }
}

int main(){
    string str;
    cin>>str;
    printPowerSet(str);
}