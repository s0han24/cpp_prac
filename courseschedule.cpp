#include <bits/stdc++.h>

using namespace std;

int topoSort(int u, vector<vector<int>> &g, vector<int> &visited, vector<int> &TopoSort){
    if(visited[u]==1) return -1;
    if(visited[u]==2) return 0;
    visited[u] = 1;
    int res;
    for(auto v: g[u]){
        res = topoSort(v, g, visited, TopoSort);
        if(res == -1) return -1;
    }
    visited[u] = 2;
    TopoSort.push_back(u);
    return 0;
}

int main(){
    int n, m;
    cin >> n >> m;
    int a,b;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }
    vector<int> visited(n, 0);
    vector<int> TopoSort;
    int res;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            res = topoSort(i, g, visited, TopoSort);
            if(res == -1){
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
    reverse(TopoSort.begin(), TopoSort.end());
    for(auto u: TopoSort){
        cout << u+1 << " ";
    }
    return 0;
}