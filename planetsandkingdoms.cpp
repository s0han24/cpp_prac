#include <bits/stdc++.h>

using namespace std;

void dfs1(vector<vector<int>> &g, stack<int> &s, vector<bool> &vis, int v){
    if(vis[v]) return;
    vis[v] = true;
    for(auto u: g[v]){
        dfs1(g,s,vis,u);
    }
    s.push(v);
}

void dfs2(vector<vector<int>> &g, vector<bool> &vis, int v, vector<int> &comp, int c_no){
    if(vis[v]) return;
    vis[v] = true;
    comp[v] = c_no;
    for(auto u: g[v]){
        dfs2(g,vis,u,comp, c_no);
    }
}

vector<int> kosaraju(vector<vector<int>> &g, vector<vector<int>> &gt){
    int n = g.size();
    vector<bool> vis(n, false);
    stack<int> s;
    vector<int> components(n);
    for(int i=0; i<n; i++){
        dfs1(g,s,vis,i);
    }
    vis.assign(n,false);
    int c = 0;
    while(!s.empty()){
        int v = s.top();
        s.pop();
        if(!vis[v]){
            c++;
            dfs2(gt,vis,v,components,c);
        }
    }
    return components;
}

int main(){
    int n,m,a,b;
    cin>>n>>m;
    vector<vector<int>> g(n), gt(n);
    for(int i=0; i<m; i++){
        cin>>a>>b;
        g[a-1].push_back(b-1);
        gt[b-1].push_back(a-1);
    }
    vector<int> res = kosaraju(g,gt);
    int k=0;
    for(int i=0; i<n; i++) if(res[i]>k) k = res[i];
    cout<<k<<endl;
    for(auto e: res){
        cout<<e<<" ";
    }
    return 0;
}