#include<bits/stdc++.h>

using namespace std;

class DSU{

    public:
    vector<int> id, sz;
    DSU(int n){
        for(int i = 0; i < n; i++){
            id.push_back(i);
            sz.push_back(1);
        }
    }

    int findParent(int i){
        if(id[i] == i) return i;
        return id[i] = findParent(id[i]);
    }

    void unionBySize(int x, int y){

        int i = findParent(x);
        int j = findParent(y);
        if(i != j){
            if(sz[i] > sz[j]){
                id[j] = i;
                sz[i] += sz[j];
            } else {
                id[i] = j;
                sz[j] += sz[i];
            }
        }
    }
};


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

int word_ladder(string &start_word, string &end_word, vector<string> &word_list){
    unordered_set<string> st(word_list.begin(), word_list.end());
    st.erase(start_word);
    queue<pair<string, int>> q;
    q.push({start_word, 1});

    while(!q.empty()){
        int count = q.size();
        string curr = q.front().first;
        int step = q.front().second;
        q.pop();

        if(curr == end_word){
            return step;
        }

        for(int i = 0; i < curr.length(); i++){
            string original = curr;
            for(char j = 'a'; j <= 'z'; j++){
                curr[i] = j;
                if(st.find(curr) != st.end()){
                    q.push({curr, step + 1});
                    st.erase(curr);
                }
            }
            curr = original; // We are doing this because we only require only one change from the original word and without which, those changes will last forever.
        }
    
    }
    return 0;
}

class Word_Ladder_II {
public:
    bool isConnected(string s,string t){
        int c=0;
        for(int i=0;i<s.length();i++)
            c+=(s[i]!=t[i]);
        return c==1;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;        
        vector<vector<string>> nodes;   
        unordered_set<string> dict(wordList.begin(),wordList.end());
        
        if (!dict.count(endWord)) return ans;
        dict.erase(beginWord);
        
        
        bool reached = false;
        nodes.push_back({beginWord});
        
        while (dict.size() && !reached) {                        
            vector<string> last = nodes.back();
            vector<string> curr;
                        
            for (int i = 0; i < last.size() && !reached; i++) {
                unordered_set<string> visited;
                string from = last[i];                                
                // check all nodes that connect
                // to the nodes of the previous level                
                for (auto& to : dict) {                    
                    if (visited.count(to)) continue;
                    if (!isConnected(from, to)) continue;                                        
                    // if one of them is "endWord" then we can stop 
                    // because this level is the shortest distance from begin
                    if (to == endWord) {                        
                        reached = true; 
                        break;
                    }
                    
                    // otherwise,
                    // add nodes for the current level
                    curr.push_back(to);   
                    visited.insert(to);                    
                }   
                // delete the visited to prevent forming cycles            
                for (auto& visited : visited) {                
                    dict.erase(visited);
                }
            }
            
            // found endWord this level
            if (reached) break;
            
            // can not add any new nodes to our level
            if (!curr.size()) break;
            
            // otherwise, record all nodes for the current level
            nodes.push_back(curr);            
        }
        
        // try but not find
        if (reached == false) return ans;
        
        // move backward
        ans.push_back({endWord});          
        for (int level = nodes.size() - 1; level >= 0; level--) {                        
            int alen = ans.size();
            while (alen) {
                vector<string> path = ans.back();
                ans.pop_back();
                string from = path.front();                
                for (string &to : nodes[level]) {                    
                    if (!isConnected(from, to)) continue;
                                        
                    vector<string> newpath = path;
                    newpath.insert(newpath.begin(), to);
                    ans.insert(ans.begin(), newpath);
                }    
                alen--;
            }             
        }
        return ans;
    }
};

class Bellman_Ford {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> distance(V, 1e8);
        distance[S] = 0;
        for(int i = 0; i < V; i++){
            for(auto edge : edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(distance[u] != 1e8 && distance[v] > w + distance[u]){
                    distance[v] = w + distance[u];
                    if(i == V - 1)
                        return {-1};
                }
            }
            
        }
        
        return distance;
    }
};

// Shortest distance from source to all other vertices in a DAG.
vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
    
    vector<pair<int, int>> graph[N];
    for(auto itr : edges){
        graph[itr[0]].push_back({itr[1], itr[2]});
    }
    
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    
    vector<int> shortest(N, -1);
    shortest[0] = 0;
    
    while(!q.empty()){
        int front = q.front().first;
        int dist = q.front().second;
        q.pop();
        for(auto itr : graph[front]){
            
            
            if(shortest[itr.first] == -1 || shortest[itr.first] >= dist + itr.second){
                q.push({itr.first, dist + itr.second});
                shortest[itr.first] = dist + itr.second;
            }
        }
        
    }
    return shortest;
}

// Finding the shortest path from the source 0 using dfs and topological sort and the concept of relaxation.
class shortest_path_DAG {
    private:
    void dfs(stack<int> &srt, int node, vector<int> &vis, int N, vector<pair<int, int>> graph[]){
        vis[node] = 1;
        
        for(auto itr : graph[node]){
            if(!vis[itr.first]){
                dfs(srt, itr.first, vis, N, graph);
                srt.push(itr.first);
            }
        }
    }
    
    stack<int> topo_sort(int N, vector<pair<int, int>> graph[]){
        stack<int> srt;
        vector<int> vis(N, 0);
        for(int i = 0; i < N; i++){
            if(!vis[i]){
                dfs(srt, i, vis, N, graph);
                srt.push(i);
            }
        }
        
        return srt;
    }
    
    public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
     
        vector<pair<int, int>> graph[N];
        for(auto itr : edges){
            graph[itr[0]].push_back({itr[1], itr[2]});
        }
        
        stack<int> srt = topo_sort(N, graph);
        
        
        
        vector<int> dis(N, 1e9);
        
        dis[0] = 0;
        
        while(!srt.empty()){
            
            int node = srt.top();
            int dist = dis[node];
            srt.pop();
            
            if(dis[node] == 1e9){
                dis[node] = -1;
                continue;
            }
            
            for(auto itr : graph[node]){
                if(dis[itr.first] > dist + itr.second){
                    dis[itr.first] = dist + itr.second;
                }
            }
        }
        

        return dis;
    }
};

// Prims method of finding the minimum spanning tree.

class Prims
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> vis(V, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // We can use the pair<int, pair<int, int>>> to store the weight, the node and its parent to construct the MST.

        int sum = 0;
        // {weight, node}
        pq.push({0, 0});
        
        while(!pq.empty()){
            
            int w = pq.top().first;
            int u = pq.top().second;
            
            pq.pop();
            
            // If the node is already part of the MST.
            if(vis[u]) continue;
            
            sum += w;
            vis[u] = 1;
            
            for(auto itr : adj[u]){
                int v = itr[0];
                int e = itr[1];
            
                // If the node is not part of the MST. You need to add it.
                if(!vis[v])
                    pq.push({e, v});
            }
            
        }
        return sum;
    }
};

// Prims - extremely efficient method of finding the minimum spanning tree.
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, int>> distances = {{0, 0}};
        for (int i = 1; i < n; ++i) {
            distances.push_back({INT_MAX, i});
        }
        int result = 0;

        while (!distances.empty()) {
            auto closest = min_element(distances.begin(), distances.end());
            result += closest->first;
            int x = points[closest->second][0];
            int y = points[closest->second][1];

            *closest = distances.back();
            distances.pop_back();

            for (auto& dist : distances) {
                int x2 = points[dist.second][0];
                int y2 = points[dist.second][1];
                dist.first = min(dist.first, abs(x - x2) + abs(y - y2));
            }
        }
        return result;
    }
};


class Bellman {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> distance(V, 1e8);
        distance[S] = 0;
        for(int i = 0; i < V; i++){
            for(auto edge : edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(distance[u] != 1e8 && distance[v] > w + distance[u]){
                    distance[v] = w + distance[u];
                    if(i == V - 1)
                        return {-1};
                }
            }
            
        }
        
        return distance;
    }
};

class MinimumMultiplications {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start == end) return 0;
        
        queue<pair<int, int>> q;
        vector<int> vis(100000, 0);
        
        q.push({start, 0});
        vis[start] = 1;
        
        while(!q.empty()){
            
            int node = q.front().first;
            int step = q.front().second;
            q.pop();
            
            for(auto itr : arr){
                int next = (node * itr) % 100000;
            
                if(node == end) return step;
                
                if(!vis[next]){
                    vis[next] = 1;
                    q.push({next, step + 1});
                }
            }
            
        }
        
        return -1;
    }
};

// For multt-source shortest path
class FloydWarshall{
    vector<vector<int>> findTheCity(int n, vector<vector<int>>& edges, int dis) {
        vector<vector<int>> mat(n, vector<int> (n, 1e9));

        for(int i = 0; i < n; i++){
                mat[i][i] = 0;
        }

        for(auto itr : edges){
            mat[itr[0]][itr[1]] = itr[2];
            mat[itr[1]][itr[0]] = itr[2];
        }

        for(int vis = 0; vis < n; vis++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    mat[i][j] = min(mat[i][j], mat[i][vis] + mat[vis][j]);
                }
            }
        }

        return mat;
    }
};

class CityWithLeastNeighborsWithinThreshold {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dis) {
        vector<vector<int>> mat(n, vector<int> (n, 1e9));

        for(int i = 0; i < n; i++){
                mat[i][i] = 0;
        }

        for(auto itr : edges){
            mat[itr[0]][itr[1]] = itr[2];
            mat[itr[1]][itr[0]] = itr[2];
        }

        for(int vis = 0; vis < n; vis++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    mat[i][j] = min(mat[i][j], mat[i][vis] + mat[vis][j]);
                }
            }
        }

        int result = 0, mini = 1e9;
        for(int i = 0; i < n; i++){
            int neighbors = 0;
            for(int j = 0; j < n; j++){
                if(mat[i][j] <= dis)
                    neighbors++;
            }
            result = (neighbors <= mini ? i : result);
            mini = min(mini, neighbors);

        }

        return result;
    }
};

class CheckForPossibleBipartition {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        DSU dsu(2 * n + 1);

        int cnt = n;

        for(auto itr : dislikes){
            if(dsu.findParent(itr[0]) == dsu.findParent(itr[1]))
                return false;
            dsu.unionBySize(itr[0], itr[1] + n);
            dsu.unionBySize(itr[1], itr[0] + n);
        }
        return true;
    }
};

class KosaRaju {

    void dfs_sort(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &s){

        vis[node] = 1;

        for(auto itr : adj[node]){
            if(!vis[itr]){
                dfs_sort(itr, adj, vis, s);
            }
        }
        s.push(node);
    }

    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &components){
        vis[node] = 1;
        components.push_back(node);
        for(auto itr : adj[node]){
            if(!vis[itr]){
                dfs(itr, adj, vis, components);
            }
        }
    }

    public:
    vector<vector<int>> kosaRaju(int V, vector<vector<int>> &adj){

        stack<int> s; vector<int> vis(V, 0);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs_sort(i, adj, vis, s);
            }
        }

        vector<vector<int>> rev(V);

        for(int i = 0; i < V; i++){
            vis[i] = 0;
            for(auto itr : adj[i]){
                rev[itr].push_back(i);
            }
        }

        vector<vector<int>> scc;

        while(!s.empty()){
            int node = s.top();
            s.pop();

            if(!vis[node]){
                vector<int> components;
                dfs(node, rev, vis, components);
                scc.push_back(components);
            }
        }
        return scc;
    }

};

class CourseScheduleIV {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<unordered_set<int>> &req){
        vis[node] = 1;
        for(auto itr : adj[node]){
            if(!vis[itr]){
                dfs(itr, adj, vis, req);
            }
            // Addding the nearby node into the requirments
            req[node].insert(itr);

            // Adding the nodes which are further down the line.
            req[node].insert(req[itr].begin(), req[itr].end());
        }
    }


public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& vec, vector<vector<int>>& queries) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        vector<vector<int>> adj(n);
        for(auto itr : vec){
            adj[itr[0]].push_back(itr[1]);
        }

        vector<int> vis(n ,0);

        vector<unordered_set<int>> req(n);

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, adj, vis, req);
            }
        }

        vector<bool> ans;
        for(auto itr : queries)
            ans.push_back(req[itr[0]].count(itr[1]) > 0);

        return ans;
    }
};

int main(){
    int n, m;
    cin >> n >> m;

    long long *arr = new long long[n];

    // ADJACENCY MATRIX TYPE OF STORING
    int adj[n + 1][n + 1];

    // ADJACENCY LIST
    vector<vector<int>> vec(n + 1);

    vector<vector<pair<int, int>>> vec1(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, weight;
        cin >> u >> v >> weight;

        // Matrix
        adj[u][v] = 1; // Edge between u to v.
        adj[v][u] = 1; // Edge between v to u.

        // List
        vec[u].push_back(v); // Edge between u to v.
        vec[v].push_back(u); // Edge between v to u.

        // For Weighted-Directed Graph
        vec1[u].push_back({v, weight}); // Only one edge is necessary and the other is not as this is a directed graph.
    }


    return 0;
}
