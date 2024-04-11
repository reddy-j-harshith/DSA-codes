#include <stdio.h>
#include <stdbool.h>

// Function to reverse a portion of the string starting from 'start' index and ending at 'end' index
void reverseWord(char str[], int start, int end) {
    while (start < end) {
        // Swap characters at start and end indices
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // Move start index forward and end index backward
        start++;
        end--;
    }
}

// Function to reverse each word in the given string
void reverseWords(char str[], int n) {
    int start = 0;
    bool inWord = false;

    // Iterate over the string character by character
    for (int i = 0; i <= n; i++) {
        // If the current character is a space or the end of string, and we were inside a word, reverse the word
        if ((str[i] == ' ' || str[i] == '\0') && inWord) {
            reverseWord(str, start, i - 1);
            inWord = false;
        }
        // If the current character is not a space and we were not inside a word, update start index
        else if (str[i] != ' ' && !inWord) {
            start = i;
            inWord = true;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // Read the string including whitespace
    char str[n + 1];
    scanf(" %[^\n]", str);

    // Reverse each word in the string
    reverseWords(str, n);

    // Print the modified string
    printf("%s\n", str);

    return 0;
}