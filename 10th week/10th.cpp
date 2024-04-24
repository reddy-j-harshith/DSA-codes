#include<bits/stdc++.h>

using namespace std;

int connected_components(vector<vector<int>> adj){
    int size = adj.size();
    queue<int> q;
    bool visited[size];
    int count = 0;

    for(int i = 1; i < size; i++){
        if(!visited[i]){
            visited[i] = true;
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

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int result = connected_components(adj);
    cout << result << endl;
}