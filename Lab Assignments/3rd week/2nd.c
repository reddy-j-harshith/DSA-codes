#include <stdio.h>
#include <stdbool.h>

int max_consecutive_troops(int n, char arr[]) {
    int freq[26] = {0};
    int max_len = 0;
    int left = 0; // left pointer of the window

    for (int right = 0; right < n; right++) {
        int index = arr[right] - 'a';
        freq[index]++;

        // If the current troop violates the condition, move left pointer
        while (freq[index] > 1) {
            freq[arr[left] - 'a']--;
            left++;
        }

        // Update max_len if the current window size is larger
        max_len = (right - left + 1 > max_len) ? right - left + 1 : max_len;
    }

    return max_len;
}

int main() {
    int n;
    scanf("%d", &n);

    char arr[n + 1];
    scanf("%s", arr);

    printf("%d\n", max_consecutive_troops(n, arr));

    return 0;
}