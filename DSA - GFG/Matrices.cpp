#include<bits/stdc++.h>

using namespace std;

void printMatrix(int* matrix[], int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
            cout<<" "<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return;
}

void printSnake(int* matrix[], int m, int n){
    for(int i = 0; i < m ; i++){
        if(i & 1)
            for(int j = n - 1; j >= 0; j--)
                cout<<matrix[i][j]<<" ";
        else    
            for(int j = 0; j < n; j++)
                cout<<matrix[i][j]<<" ";
    }
}


void printMatrixBoundary(int* mat[], int m, int n){
    if(m == 1)
        for(int i = 0; i < n; i++)
            cout<<mat[0][i]<<" ";
    else if (n == 1)
        for(int i = 0; i < m ; i++)
            cout<<mat[i][0]<<" ";
    else
        for(int i = 0; i < n; i++)
            cout<<mat[0][i]<<" ";
        for(int i = 1; i < m; i++)
            cout<<mat[i][n - 1]<<" ";
        for(int i = n - 2; i >= 0; i--)
            cout<<mat[m - 1][i]<<" ";
        for(int i = m - 1; i >= 1; i--)
            cout<<mat[i][0]<<" ";
}


// For Transposing a square matrix
void transpose(int* mat[], int n){
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            swap(mat[i][j], mat[j][i]);
}

void rotateMatrix(int* mat[], int m, int n){
    
    transpose(mat, n);

    for(int j = 0; j < m << 1; j++)
        for(int i = 0; i < n; i++){
            swap(mat[j][i], mat[m - j - 1][i]);
        }
}


void n_spiral(int r, int c){
    int count = 1;
    int* matrix[r];
    for(int i = 0; i < r; i++)
        matrix[i] = new int[c];
    int left = 0, top = 0, right = c - 1, bottom = r - 1;
    while(top <= bottom && left <= right){
        
        for(int i = left; i <= right; i++)
            matrix[top][i] = count++;
        top++;

        for(int i = top; i <= bottom; i++)
            matrix[i][right] = count++;
        right--;

        if(top <= bottom){
            for(int i = right; i >= left; i--)
                matrix[bottom][i] = count++;
            bottom--;
        }

        if(left <= right){
            for(int i = bottom; i >= top; i--)
                matrix[i][left] = count++;
            left++;
        }
    }

    printMatrix(matrix, r, c);
    return;
}

void printSpiral(int* matrix[], int r, int c){
    int left = 0, top = 0, right = c - 1, bottom = r - 1;
    while(top <= bottom && left <= right){
        
        for(int i = left; i <= right; i++)
            cout<<matrix[top][i]<<" ";
        top++;

        for(int i = top; i <= bottom; i++)
            cout<<matrix[i][right]<<" ";
        right--;

        if(top <= bottom){
            for(int i = right; i >= left; i--)
                cout<<matrix[bottom][i]<<" ";
            bottom--;
        }

        if(left <= right){
            for(int i = bottom; i >= top; i--)
                cout<<matrix[i][left]<<" ";
            left++;
        }
    }

    return;
}

void matrixSearch(int* matrix[], int r, int c, int x){
    int i = 0, j = c - 1;
    while(i < r && j >= 0){
        if(matrix[i][j] == x){
            cout<<"Found at ("<<i<<", "<<j<<").";
            return;
        } else if(matrix[i][j] < x){
            i++;            
        } else {
            j--;
        }   
    }

    cout<<"Not Found";
}

int matrixMedian(int matrix[][INT_MAX], int r, int c){
    int mini = matrix[0][0], maxi = matrix[0][c - 1];
    for(int i = 0; i < r; i++){
        mini = min(mini, matrix[i][0]);
        maxi = max(maxi, matrix[i][c - 1]);
    }

    int medPos = (r * c + 1) / 2;
    while(mini < maxi){
        int mid = (maxi - mini) / 2;
        int midPos = 0;
        for(int i = 0; i < r; i++)
            midPos += upper_bound(matrix[i], matrix[i] + c, mid) - matrix[i];

        if(midPos < medPos)
            mini = mid + 1;
        else
            maxi = mid;
    }
    return mini;
}

int main(){
    int r, c;
    cin>>r>>c;

    int* matrix[r];
    for(int i = 0; i < r; i++){
        matrix[i] = new int[c];
        for(int j = 0; j < c; j++)
            cin>>matrix[i][j];
    }

    printSpiral(matrix, r, c);

    // n_spiral(r, c);
}