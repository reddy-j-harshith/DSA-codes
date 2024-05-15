#include<bits/stdc++.h>

using namespace std;

vector<int> bfs(vector<vector<int>> &adj, int n){

    vector<int> visited(n + 1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;

    vector<int> vec;

    while(!q.empty()){

        int node = q.front();
        q.pop();
        vec.push_back(node);

        for(auto itr : adj[node]){
            if(!visited[itr]){
                q.push(itr);
                visited[itr] = true;
            }
        }
    }
    return vec;
}

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &vec){

    visited[node] = true;
    vec.push_back(node);

    for(auto itr : adj[node]){
        if(!visited[itr]){
            dfs(itr, adj, visited, vec);
        }
    }
}

vector<int> dfsOfGraph(vector<vector<int>> &adj, int n){

    vector<bool> visited(n + 1, false);
    int start = 1;
    vector<int> ls;

    dfs(start, adj, visited, ls);

    return ls;
}

int connected_components(vector<vector<int>> &adj, int n){

    vector<bool> visited(n + 1, false);
    queue<int> q;
    int count = 0;

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            q.push(i);
            count++;
            while(!q.empty()){

                int node = q.front();
                q.pop();

                for(auto itr : adj[node]){
                    if(!visited[itr]){
                        visited[itr] = true;
                        q.push(itr);
                    }
                }
            }
        }
    }
    return count;
}

void dfs_connected(int node, vector<vector<int>> adj, vector<bool> &visited){
    
    visited[node] = true;

    for(auto itr : adj[node]){
        if(!visited[itr]){
            visited[itr] = true;
            dfs_connected(itr, adj, visited);
        }
    }

}

int connected_components_dfs(vector<vector<int>> adj, int n){

    vector<bool> visited(n + 1, false);

    int count = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs_connected(i, adj, visited);
            count++;
        }
    }
    return count;
}

int rotten_oranges(vector<vector<int>> grid){

    int n = grid.size();
    int m = grid[0].size();
    int cntFresh = 0, time = 0;
    queue<pair<pair<int, int>, int>> q;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2){
                q.push({{i, j}, time});
            }

            if(grid[i][j] == 1){
                cntFresh++;
            }
        }
    }

    int count = 0;

    int row[] = {0, -1, 0, 1};
    int col[] = {1, 0, -1, 0};

    while(!q.empty()){

        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        time = max(t, time);

        for(int i = 0; i < 4; i++){
            int R = r + row[i];
            int C = c + col[i];

            if(R >= 0 && c >= 0 && R < n && C < m && grid[R][C] == 1){
                q.push({{R, C}, t + 1});
                count++;
                grid[R][C] = 2;
            }
        }
    }
    if(count < cntFresh) return -1;
    
    return time;
}

void flood_fill(vector<vector<int>> &image, pair<int, int> point, int newColor){

    if(image[point.first][point.second] == newColor) return;

    int n = image.size();
    int m = image[0].size();

    queue<pair<int, int>> q;
    q.push({point.first, point.second});
    int Oldcolor = image[point.first][point.second];
    image[point.first][point.second] = newColor;

    int row[] = {0, -1, 0, 1};
    int col[] = {1, 0, -1, 0};

    while(!q.empty()){

        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int R = r + row[i];
            int C = c + col[i];

            if(R >= 0 && C >= 0 && R < n && C < m && image[R][C] == newColor){
                q.push({R, C});
                image[R][C] = newColor;
            }
        }
    }
}

void dfs_floodfill(vector<vector<int>> &image, int r, int c, int color, int newColor){

    if(image[r][c] == color){
        image[r][c] = newColor;
        int row[] = {1, 0, -1, 0};
        int col[] = {0, -1, 0, 1};

        for(int i = 0; i < 4; i++){
            int R = r + row[i];
            int C = c + col[i];

            if(R >= 0 && c >= 0 && R < image.size() && C > image[0].size() && image[R][C] == color){
                image[R][C] = newColor;
                dfs_floodfill(image, R, C, color, newColor);
            }
        }
    }
}
vector<vector<int>> flood_fill_dfs(vector<vector<int>> image, int sr, int sc, int newColor){

    int color = image[sr][sc];
    if(color == newColor) return image;
    dfs_floodfill(image, sr, sc, color, newColor);
    return image;
}

bool cycle_detection_bfs(vector<vector<int>> adj){
    
    int n = adj.size();
    int visited[n] = {0};
    queue<pair<int, int>> q; // The second number of maintaining the parent of the node from which it came from.


    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            visited[i] = 1;
            q.push({i, -1});
            while(!q.empty()){

                int node = q.front().first;
                int parent = q.front().second;
                q.pop();

                for(auto itr : adj[node]){
                    if(!visited[itr]){
                        visited[itr] = 1;
                        q.push({itr, node});
                    } else if (parent != itr){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

// You maintain / carry the parent of the current node with it to examine if a node was already visited.
bool dfs_cycle(pair<int, int> node, vector<vector<int>> &adj, int vis[]){
    vis[node.first] = 1;

    for(auto itr : adj[node.first]){
        if(!vis[itr]){
           if(dfs_cycle({itr, node.first}, adj, vis)){
            return true;
           }
        } else if(node.second != itr) {
            return true;
        }
    }
    return false;
}

bool cycle_detection_dfs(vector<vector<int>> &adj){

    int n = adj.size();
    int visited[n] = {0};

    for(int i = 1; i <= n; i++){
        if(!visited[i])
            if(dfs_cycle({i, -1}, adj, visited))
                return true;
    }
    return false;
}

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    queue<pair<int, int>> q;

    int row[] = {-1, 0, 1, 0};
    int col[] = {0, 1, 0, -1};

    vector<vector<int>> ret(n, vector<int> (n, 0));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            q.push({i, j});

            int visited[m][n] = {0};
            int dis = 0;
            while(!q.empty()){
                int r = q.front().first, c = q.front().second;
                visited[r][c] = 1;
                if(mat[r][c] == 0) ret[i][j] = dis;

                for(int i = 0; i < 4; i++){
                    int R = r + row[i];
                    int C = c + col[i];
                    if(r >= 0 && c >= 0 && r < m && c < n && !visited[R][C]){
                        q.push({R, C});
                        dis++;
                    }
                }
            }
        }
    }
    return ret;
}


bool dfs_path_naive(int node, vector<int> adj[], int visited[], int path[]){
        visited[node] = 1;
        path[node] = 1;

        for(auto itr : adj[node]){
            if(!visited[itr]){
                if(dfs_path_naive(itr, adj, visited, path)){
                    return true;
                }
            } else if (path[itr]){
                return true;
            }
        }
        path[node] = 0;
        return false;
    }

bool directional_cycle_naive(vector<int> adj[], int v){

    int visited[v + 1] = {0};
    int path[v + 1] = {0};
    for(int i = 1; i <= v; i++){
        if(!visited[i]){
            if(dfs_path_naive(i, adj, visited, path))
                return true;
        }
    }
    return false;
}

bool dfs_path(int node, vector<int> adj[], int visited[]){
    visited[node] = 2;

    for(auto itr : adj[node]){
        if(visited[itr] == 0){
            if(dfs_path(itr, adj, visited))
                return true;
        } else if(visited[itr] == 2){
            return true;
        }
    }
    visited[node] = 1;
    return false;
}

bool directional_cycle(int V, vector<int> adj[]){

    int visited[V + 1] = {0};
    for(int i = 1; i <= V; i++){
        if(!visited[i]){
            if(dfs_path(i, adj, visited))
                return true;
        }
    }
    return false;
}

bool bipartite_bfs(int v, vector<vector<int>> adj){

    int visited[v + 1] = {-1};
    queue<int> q;
    for(int i = 1; i <= v; i++){
        if(visited[i] == -1){
            visited[i] = 1;
            q.push(i);

            while(!q.empty()){

                int node = q.front();
                q.pop();
                for(auto itr : adj[node]){
                    if(visited[itr] == -1){
                        q.push(itr);
                        visited[itr] = (visited[node] == 0) ? -1 : 0;
                    } else if(visited[node] == visited[itr]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool dfs_bipartite(int node, int color, vector<vector<int>> adj, vector<int> &vis){

    vis[node] = color;

    for(auto itr: adj[node]){
        if(vis[itr] == -1){
            if(!dfs_bipartite(itr, (color == 0 ? 1 : 0), adj, vis))
                return false;
        } else if(vis[node] == vis[itr])
            return false;
    }
    return true;
}

bool isBipartite(int v, vector<vector<int>> adj){

    vector<int> vis(v + 1, -1);
    for(int i = 1; i <= v; i++){
        if(vis[i] == -1){
            if(!dfs_bipartite(i, 0, adj, vis)){
                return false;
            }
        }
    }
    return true;
}

int number_of_islands(vector<int> adj[], int n){

    int m = adj[0].size();
    int count = 0;

    int row[] = {0, 1, 0, -1, 1, -1, 1, -1};
    int col[] = {1, 0, -1, 0, 1, -1, -1, 1};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(adj[i][j] == 1){

                count++;

                adj[i][j] = 2;
                stack<pair<int, int>> s;
                s.push({i, j});

                while(!s.empty()){

                    int r = s.top().first;
                    int c = s.top().second;
                    s.pop();

                    for(int k = 0; k < 8; k++){
                        int R = r + row[k];
                        int C = c + col[k];
                        if(R >= 0 && R < n && C >= 0 && C < m && adj[R][C] == 1){
                            adj[R][C] = 2;
                            s.push({R, C});
                        }
                    }

                }

            }
        }
    }

    return count;
}

void dfs_enclave(pair<int, int> node, vector<int> adj[], int n, int &count, bool &flag){


    int r = node.first;
    int c = node.second;

    adj[r][c] = 0;
    if(r > 0 && r < n - 1 && c > 0 && c < adj[0].size() - 1){
        count++;
    } else {
        flag = true;
    }

    int row[] = {0, 1, 0, -1};
    int col[] = {1, 0, -1, 0};
    for(int i = 0; i < 4; i++){
        int R = r + row[i];
        int C = c + col[i];
        if(R >= 0 && R < n && C >= 0 && C < adj[0].size() && adj[R][C] == 1){
            dfs_enclave({R, C}, adj, n, count, flag);
        }
    }
}

int no_enclaves(vector<int> adj[], int n){

    int m = adj[0].size(), count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(adj[i][j] == 1){
                int tempCount = 0;
                bool flag = false;
                dfs_enclave({i, j}, adj, n ,tempCount, flag);
                
                if(!flag)
                    count += tempCount;
            }
        }
    }
    return count;
}


void surrounded_dfs(int r, int c, vector<vector<char>> &mat, vector<vector<int>> &vis){
    vis[r][c] = 1;
    int n = mat.size();
    int m = mat[0].size();

    int row[] = {0, 1, 0, -1};
    int col[] = {-1, 0, 1, 0};
    for(int i = 0; i < 4; i++){
        int R = r + row[i];
        int C = c + col[i];
        if(R >= 0 && R < n && C >= 0 && C < m && mat[R][C] == 'O' && vis[R][C] == 0)
            surrounded_dfs(R, C, mat, vis);
    }
}

void surrounded(vector<vector<char>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> vis(n, vector<int> (m, 0));

    for(int i = 0; i < n; i++){
        if(mat[i][0] == 'O' && vis[i][0] == 0) surrounded_dfs(i, 0, mat, vis);
        if(mat[i][m - 1] == 'O' && vis[i][m - 1] == 0) surrounded_dfs(i, m - 1, mat, vis);
    }

    for(int i = 0; i < m; i++){
        if(mat[0][i] == 'O' && vis[0][i] == 0) surrounded_dfs(0, i, mat, vis);
        if(mat[n - 1][i] == 'O' && vis[n - 1][i] == 0) surrounded_dfs(n - 1, i, mat, vis);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis[i][j] == 0)
                mat[i][j] = 'X';
        }
    }
}

int bfs_nearest_naive(int r, int c, vector<vector<int>> &adj){

    int n = adj.size(), m = adj[0].size();
    vector<vector<int>> vis(n, vector<int> (m, 0));
    queue<pair<pair<int, int>, int>> q;

    q.push({{r, c}, 0});
    vis[r][c] = 1;

    int row[] = {0, 1, 0, -1};
    int col[] = {1, 0, -1, 0};

    while(!q.empty()){

        int r = q.front().first.first;
        int c = q.front().first.second;
        int d = q.front().second;
        q.pop();

        if(adj[r][c] == 0) return d;

        for(int i = 0; i < 4; i++){
            int R = r + row[i];
            int C = c + col[i];
            if(R >= 0 && R < n && C >= 0 && C < m && !vis[R][C]){
                vis[R][C] = 1;
                q.push({{R, C}, d + 1});
            }
        }
    }
    return -1;
}

vector<vector<int>> nearest_matrix_naive(vector<vector<int>> &adj){

    int n = adj.size(), m = adj[0].size();
    vector<vector<int>> dis(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int result = bfs_nearest_naive(i, j, adj);
            dis[i].push_back(result);
        }
    }
    return dis;
}


vector<vector<int>> nearest_matrix(vector<vector<int>> &grid){
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dis(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 0){
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }

    int row[] = {0, 1, 0, -1};
    int col[] = {1, 0, -1, 0};

    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int d = q.front().second;
        q.pop();

        dis[r][c] = d;
        for(int i = 0; i < 4; i++){
            int R = r + row[i];
            int C = c + col[i];
            if(R >= 0 && R < n && C >= 0 && C < m && !vis[R][C]){
                vis[R][C] = 1;
                q.push({{R, C}, d + 1});
            }
        }
    }
    return dis;
}

int word_ladder(string start, string end, vector<string> &wordList){

    unordered_set<string> s(wordList.begin(), wordList.end());

    s.erase(start);

    queue<pair<string, int>> q;
    q.push({start, 0});

    while(!q.empty()){

        auto word = q.front().first;
        int dis = q.front().second;
        q.pop();
        if(word == end) return dis;

        for(int i = 0; i < word.length(); i++){

            string original = word;
            for(char ch = 'a'; ch < 'z'; ch++){
                word[i] = ch;
                if(s.find(word) != s.end()){
                    s.erase(word);
                    q.push({word, dis + 1});
                }
            }
        }
    }
    return 0;
}

pair<int*, bool> bellman_ford(vector<vector<pair<int, int>>> &adj, int n){
    int *dis = new int[n + 1];
    for(int i = 2; i <= n; i++){
        dis[i] = INT_MAX;
    }

    dis[1] = 0;
    for(int i = 1; i < n; i++){

        for(int u = 1; u <= n; u++){
            for(auto v : adj[u]){
                if(dis[u] != INT_MAX && dis[v.first] > dis[u] + v.second)
                    dis[v.first] = dis[u] + v.second;
            }
        }
    }

    bool flag = true;
    for(int i = 2; i <= n; i++)
        if(dis[i] != INT_MAX)
            flag = false;
    
    return {dis, flag};
}

