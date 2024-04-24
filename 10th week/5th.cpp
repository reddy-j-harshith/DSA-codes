#include<bits/stdc++.h>

using namespace std;

vector<int> topo_sort(int v, vector<int> adj[]){

    vector<int> path;
    int indeg[v + 1] = {0};
    for(int i = 1; i <= v; i++){
        for(auto itr : adj[i]){
            indeg[itr]++;
        }
    }
    
    int count = 0;
    queue<int> q;
    for(int i = 1; i <= v; i++){
        if(indeg[i] == 0){
            q.push(i);
            count++;
        }
    }

    if(count == 0) { cout << "IMPOSSIBLE" << endl; return path; }

    while(!q.empty()){

        int node = q.front();
        q.pop();
        path.push_back(node);

        for(auto itr : adj[node]){
            indeg[itr]--;
            if(indeg[itr] == 0){
                q.push(itr);
                count++;
            }
        }
    }

    if(count < v) { cout << "IMPOSSIBLE" << endl; return path; }

    return path;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);

    }

    vector<int> result = topo_sort(n, adj);

    if(result.size() != 0){
        for(auto itr : result)
            cout << itr << " ";
    }
}