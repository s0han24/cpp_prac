#include <bits/stdc++.h>
#define INF -1
#define ll long long
 
using namespace std;
 
void prim_using_set(vector<vector<pair<int,int>>> &g, vector<ll> &d, int v){
    set<pair<ll,ll>> s;
    vector<int> known(g.size());
    for(int i=0; i<(int)g.size(); i++) d[i] = INF;
    d[v] = 0;
    s.insert({0, v});
    while(!s.empty()){
        int u = (s.begin())->second;
        s.erase(s.begin());
        
        known[u] = 1;
        for(auto i : g[u]){
            if(d[i.second] == INF || d[i.second] > i.first){
                if(known[u]) continue;
                s.erase({d[i.second], i.second}); // to update the value in the set, we need to remove the old value and insert the new one
                d[i.second] = i.first;
                s.insert({d[i.second], i.second});
            }
        }
    }
}
 
void dfs(vector<vector<pair<int,int>>> &g, vector<int> &vis, int v){
    if(vis[v]) return;
    vis[v]=1;
    for(auto u: g[v]){
        dfs(g,vis,u.second);
    }
}
 
int main(){
    int n, m, a, b, w;
    cin >> n >> m;
    vector<vector<pair<int,int>>> g(n);
    vector<ll> d(n);
    for(int i=0; i<m; i++){
        cin >> a >> b >> w;
        a--; b--;
        g[a].push_back({w, b});
        g[b].push_back({w, a});
    }
    vector<int> vis(n);
    dfs(g,vis,0);
    for(int i=0; i<n; i++){
        if(!vis[i]){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    prim_using_set(g, d, 0);
    ll sum = 0;
    for(int i=0; i<n; i++){
        sum+=d[i];
    }
    cout<<sum;
    return 0;
}