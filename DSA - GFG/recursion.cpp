#include<iostream>
#include<math.h>
#include<cmath>

using namespace std;
int max_pieces(int n, int a, int b, int c){
    if(n == 0) return 0; 
    if(n < 0) return -1; 

    int temp1 = max_pieces(n - a, a, b, c);
    int temp2 = max_pieces(n - b, a, b, c);
    int temp3 = max_pieces(n - c, a, b, c);

    int max;
    if(temp1 > temp2){
        int max = (temp1 > temp3) ? (temp1) : (temp3);
    } else{
        int max = (temp2 > temp3) ? (temp2) : (temp3);
    }

    if(max == -1) return -1;

    return max + 1;

}


int sum(int n){
    if(n <= 0) { return n; }
    return (n % 10) + sum(n / 10);
}

bool checkPalindrome(string &str){
    int length = str.length();
    for(int i = 0; i < length / 2; i++){
        if(str[i] != str[length - i - 1])
            return false;
    }
    return true;
}
bool recursPalindrome(string str, int lo, int hi){
    int length = hi - lo;

    if(length ==  1 || length == 0){
        return true;
    }
    if(str[lo] == str[hi]){
        return recursPalindrome(str, lo + 1, hi - 1);
    } else{
        return false;
    }
}


bool palindromeAPI(string str){
    return recursPalindrome(str, 0, str.length() - 1);
}

void strSubset(string str){
    int length = str.length();
    int exp = pow(2, length);
    for(int counter = 0; counter < exp; counter++){
        for(int i = 1; i < length; i++){
            if((counter & 1 << i) != 0){
                cout<<str[i];
            }
        }
        cout<<"\n";
    }
}

void strSubSetRec(string str, string curr, int i){
    if(i == str.length()){ cout<<curr<<endl; return ; }

    strSubSetRec(str, curr, i + 1);
    strSubSetRec(str, curr + str[i], i + 1);
}

int countHanoi(int n){
    if(n <= 1){ return n; }
    else      { return 2 * countHanoi(n - 1) + 1; }
}

void Hanoi(int n, char A = 'A', char B = 'B', char C = 'C'){
    if(n == 1) { cout<<"Move Disk 1 from "<<A<<" to "<<C<<endl; return; }
    Hanoi(n - 1, A, C, B);
    cout<<"Move Disk "<<n<<" from "<<A<<" to "<<C<<endl;
    Hanoi(n - 1, B, A, C);
}

int jos(int n, int k){
    if(n == 1) return 0;
    return (jos(n - 1, k) + k) % n;
}

int subSetSum(int* arr, int i, int sum, int k){
    if(sum == k){
        return 1;
    } if(i == -1){
        return 0;
    }
    return (subSetSum(arr, i - 1, sum, k) + subSetSum(arr, i - 1, sum + arr[i], k));

}

void swap(char &a, char &b){// swapping the characters
    char temp = a;
    a = b;
    b = temp;
    return;
}

void perm(string str, int lo = 0){// Swapping the characters in the string itelf.
    if (lo == str.length()){
        cout<<str<<" ";
    }
    for(int i = lo; i < str.length(); i++){
        swap(str[i], str[lo]);
        perm(str, i + 1);
        swap(str[lo], str[i]);
    }
}



// To give the number of ways you can divide the sum in the given denominations if they are available infintely many times.
int count(int* arr, int n, int sum, int i){
    if(sum == 0){
        return 1;
    } else if (sum < 0 || i == n){
        return 0;
    }

    int include = count(arr, n, sum - arr[i], i);
    int exclude = count(arr, n, sum, i + 1);

    return include + exclude;
}


int main(){

    int n, k;
    cin>>n>>k;
    cout<<jos(n, k);
}