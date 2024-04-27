#include <stdio.h>

int longest_palindromic_substring_length(char *s, int n) {
    if (n == 0) {
        return 0;
    }

    int dp[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    int max_length = 1;

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i+1]) {
            dp[i][i+1] = 1;
            max_length = 2;
        }
    }

    for (int length = 3; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = 1;
                max_length = length;
            }
        }
    }

    return max_length;
}

int main() {
    int n;
    scanf("%d", &n);
    
    char s[n+1];
    scanf("%s", s);

    // Output
    printf("%d\n", longest_palindromic_substring_length(s, n));

    return 0;
}
