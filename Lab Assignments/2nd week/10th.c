#include<stdio.h>

void generateSpiralMatrix(int N) {
    int matrix[N][N];

    int top = 0, bottom = N - 1, left = 0, right = N - 1;
    int num = 1;

    while (top <= bottom && left <= right) {
        // Fill top row
        for (int i = left; i <= right; ++i) {
            matrix[top][i] = num++;
        }
        ++top;

        // Fill right column
        for (int i = top; i <= bottom; ++i) {
            matrix[i][right] = num++;
        }
        --right;

        // Fill bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                matrix[bottom][i] = num++;
            }
            --bottom;
        }

        // Fill left column
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = num++;
            }
            ++left;
        }
    }

    // Print the Spiral Matrix
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int N;
    scanf("%d", &N);

    generateSpiralMatrix(N);

    return 0;
}