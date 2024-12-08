#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<int>> &g, int v, vector<int> &vis, vector<int> &prev, int newPrev, int oldPrev){
    if(vis[v] == 1){
        prev[v] = newPrev;
        return v;
    }
    vis[v] = 1;
    prev[v] = newPrev;
    int res;
    for(auto u: g[v]){
        if(u == newPrev) continue;
        res = dfs(g, u, vis, prev, v, newPrev);
        if(res != -1 && prev[res] != -1) return res;
    }
    return -1;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n);
    int u, v;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> vis(n), prev(n, -1);
    int res;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            res = dfs(g, i, vis, prev, -1, -1);
            if(res != -1) break;
        }
    }
    
    if(res == -1){
        cout<<"IMPOSSIBLE";
    }else{
        vector<int> path;
        path.push_back(res);
        int curr = prev[res];
        while(curr != res){
            path.push_back(curr);
            curr = prev[curr];
        }
        path.push_back(res);
        cout<<path.size()<<"\n";
        for(auto e: path){
            cout<<e+1<<" ";
        }
    }
    return 0;
}