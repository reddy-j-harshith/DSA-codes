    #include<stdio.h>

    void swap(char* a, char* b){
        char temp = *a;
        *a = *b;
        *b = temp;
    }

    int main(){
        int n, m;
        scanf("%d %d", &n, &m);
        char arr[n][m];
        for(int i = 0; i < n ; i++)
            scanf("%s", arr[i]);

        for(int i = 0; i < m; i++){
            int anc = n - 1;
            for(int j = n - 1; j >= 0; j--){
                if(arr[j][i] == 'o'){
                    anc = j - 1;
                }else if(arr[j][i] == '*'){
                    swap(&arr[j][i], &arr[anc--][i]);
                }else{// if arr[j][i] == '.'
                    continue;
                }
            }

        }

        printf("\n\n");

        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m; j++)
                printf("%c", arr[i][j]);
            printf("\n");

        }
    }