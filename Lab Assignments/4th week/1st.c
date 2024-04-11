#include <stdio.h>

void convertThreeDigits(int num) {
    const char* ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    const char* teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    const char* tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    int hundred = num / 100;
    int ten = (num % 100) / 10;
    int one = num % 10;

    // Add hundred's place if it exists
    if (hundred > 0) {
        printf("%s hundred ", ones[hundred]);
    }

    // Add ten's place and one's place
    if (ten == 1) {
        //if (hundred > 0) printf(" ");
        printf("%s", teens[one]);
    } else if (ten > 1) {
       // if (hundred > 0) printf(" ");
        printf("%s", tens[ten]);
        if (one > 0) {
            printf(" %s", ones[one]);
        }
    } else if (one > 0) {
        if (hundred > 0) printf(" ");
        printf("%s", ones[one]);
    }
}

int main() {
    // Read the input integer
    long long n;
    scanf("%lld", &n);

    // If n is 0, simply print "zero"
    if (n == 0) {
        printf("zero\n");
        return 0;
    }

    // Convert each group of three digits
    int groups[5] = {0}; // Maximum number of groups for a 12-digit number
    int i = 0;
    while (n > 0) {
        groups[i++] = n % 1000;
        n /= 1000;
    }

    // Print the English representation of each group in reverse order
    for (int j = i - 1; j >= 0; j--) {
        convertThreeDigits(groups[j]);
        if (j > 0 && groups[j] > 0) {
            printf(" ");
            // Print the appropriate suffix for the group
            switch (j) {
                case 1: printf("thousand "); break;
                case 2: printf("million "); break;
                case 3: printf("billion "); break;
                case 4: printf("trillion "); break;
                // Add more cases if necessary for larger numbers
            }
        }
    }

    printf("\n");

    return 0;
}