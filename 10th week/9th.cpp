#include<bits/stdc++.h>

using namespace std;

int islands(vector<vector<int>> &grid){

    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int, int>> q;

    int count = 0;

    int delrow[] = {1, 0, -1, 0};
    int delcol[] = {0, 1, 0, -1};

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1){
                grid[i][j] = 2;
                q.push({i, j});
                count++;

                while(!q.empty()){

                    int r = q.front().first;
                    int c = q.front().second;

                    q.pop();

                    for(int k = 0; k < 4; k++){
                        int R = r + delrow[k];
                        int C = c + delcol[k];
                        if(R < m && C < n && R >= 0 && C >= 0
                            && grid[R][C] == 1){
                            grid[R][C] = 2;
                            q.push({R, C});
                        }
                    }

                }
            }
        }
    }
    return count;
}

int main(){
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int temp;
            cin >> temp;
            grid[i].push_back(temp);
        }
    }

    int result = islands(grid);
    cout << result << endl;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}