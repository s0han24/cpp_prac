#include <bits/stdc++.h>

using namespace std;

void topoSort(int u, vector<vector<int>> &g, vector<int> &visited, vector<int> &TopoSort, vector<int> &prev){
    visited[u] = 1;
    for(auto v: g[u]){
        if(visited[v] == 0){
            prev[v] = u;
            topoSort(v, g, visited, TopoSort, prev);
        }
    }
    TopoSort.push_back(u);
}

int main(){
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
    }
    vector<int> prev(n, -1);
    vector<int> TopoSort;
    vector<int> visited(n, 0);
    topoSort(0, g, visited, TopoSort, prev);
    reverse(TopoSort.begin(), TopoSort.end());
    vector<int> dp(n, 0);
    for(auto u: TopoSort){
        for(auto v: g[u]){
            if(dp[u] + 1 > dp[v]){
                dp[v] = dp[u] + 1;
                prev[v] = u;
            }
        }
    }
    if(prev[n-1] == -1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vector<int> path;
    int node = n-1;
    while(node != -1){
        path.push_back(node);
        node = prev[node];
    }
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for(auto u: path){
        cout << u+1 << " ";
    }
    cout << endl;
    return 0;
}