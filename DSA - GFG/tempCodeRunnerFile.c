#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);

    char arr[t][6]; // Increase size to accommodate null terminator

    for (int i = 0; i < t; i++)
        scanf("%s", arr[i]);

    for (int i = 0; i < t; i++) {
        int temp = 0;
        temp = ((arr[i][0] - 48) * 10) + arr[i][1] - 48;
        if (temp == 0){
            temp = 12;
            arr[i][0] = ((temp / 10) + 48); arr[i][1] = ((temp % 10) + 48);
            printf("%s AM\n", arr[i]);
        } else if (temp > 12) {
            temp -= 12;
            arr[i][0] = ((temp / 10) + 48); arr[i][1] = ((temp % 10) + 48);
            printf("%s PM\n", arr[i]); 
        } else {
            if(temp == 12)
                printf("%s PM\n", arr[i]);
            else
                printf("%s AM\n", arr[i]);
        }
    }

    return 0;
}
