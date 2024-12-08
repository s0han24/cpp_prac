#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

void topoSort(int u, vector<vector<int>> &g, vector<int> &visited, vector<int> &TopoSort){
    visited[u] = 1;
    for(auto v: g[u]){
        if(!visited[v]) topoSort(v, g, visited, TopoSort);
    }
    TopoSort.push_back(u);
}

int main(){
    int n,m;
    cin>>n>>m;
    int a,b;
    vector<vector<int>> g(n);
    for(int i=0; i<m; i++){
        cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
    }
    vector<int> vis(n,0);
    vector<int> TopoSort;
    topoSort(0, g,vis,TopoSort);
    reverse(TopoSort.begin(), TopoSort.end());
    vector<int> dp(n,0);
    for(auto i: g[0]){
        dp[i] += 1;
    }
    for(auto u: TopoSort){
        for(auto v: g[u]){
            dp[v] = (dp[v]+dp[u])%MOD;
        }
    }
    cout<<dp[n-1];
    return 0;
}