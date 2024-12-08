#include <bits/stdc++.h>

using namespace std;

void dfs1(vector<vector<int>> &g, int v, vector<int> &vis, stack<int> &s){
    if(vis[v]) return;
    vis[v] = 1;
    for(auto u: g[v]){
        dfs1(g,u,vis,s);
    }
    s.push(v);
}

void dfs2(vector<vector<int>> &g, int v, vector<int> &vis){
    if(vis[v]) return;
    vis[v] = 1;
    for(auto u: g[v]){
        dfs2(g,u,vis);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    int a,b;
    vector<vector<int>> g(n);
    vector<vector<int>> gt(n);
    for(int i=0; i<m; i++){
        cin>>a>>b;
        a--; b--;
        g[a].push_back(b);
        gt[b].push_back(a);
    }
    stack<int> s;
    vector<int> vis(n);
    for(int i=0; i<n; i++){
        if(!vis[i]) dfs1(g,i,vis,s);
    }
    vis.assign(n,0);
    dfs2(gt,s.top(),vis);
    for(int i=0; i<n; i++){
        if(!vis[i]){
            cout<<"NO\n";
            cout<<i+1<<" "<<s.top()+1;
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}