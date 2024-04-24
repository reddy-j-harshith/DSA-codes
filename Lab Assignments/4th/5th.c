#include <stdio.h>
#include <string.h>

char digits[20];
int n, k;
long long l, r;
long long count = 0;

void countSalaries(int index, int sum, long long current) {
    if (index == n) {
        if (sum == k && current >= l && current <= r) {
            count++;
        }
        return;
    }

    if (digits[index] == '?') {
        for (int i = (index == 0 ? 1 : 0); i <= 9; i++) { // Adjusted here to ensure no leading zeros
            countSalaries(index + 1, sum + i, current * 10 + i);
        }
    } else {
        int digit = digits[index] - '0';
        countSalaries(index + 1, sum + digit, current * 10 + digit);
    }
}

int main() {
    scanf("%d %d %lld %lld", &n, &k, &l, &r);
    scanf("%s", digits);

    countSalaries(0, 0, 0);

    printf("%lld\n", count);

    return 0;
}