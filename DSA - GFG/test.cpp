#include<bits/stdc++.h>

using namespace std;

#define MAX_SIZE 100000


int main() {
    int t;
    cin >> t;
    for(int h = 0; h < t; h++){
        int n, x, y;
        cin>>n>>x>>y;


        if(n == 3){
            cout<<"1"<<endl;
        }

        if(n < 3){
            cout<<"0"<<endl;
        }

        int result = (x > 2) ? x - 2 : 0;

        int *arr = new int[MAX_SIZE];
        for(int i = 0; i < x; i++){
            cin>>arr[i];
        }

        int count[n + 1] = {0};

        for(int i = 0; i < x; i++){
            count[arr[i]]++;
        }

        for(int i = 1; i <= n - 2; i++){
            if(count[i] && count[i + 2] && !count[i + 1])
                result++;
        }

        if(count[n - 1] && count[1] && !count[n])
            result++;
        cout<<result<<endl;
    }
    return 0;
}
