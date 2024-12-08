#include <bits/stdc++.h>
#define ll long long
#define f(l, r, k) for(int i=l; i<r; i+=k)
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define vi vector<int>
#define vl vector<long long>

using namespace std;

void bfs(vector<vi> &g, vi &vis, vi &prev){
    queue<pair<int,int>> q;
    q.push({0, -1});
    while(!q.empty()){
        pair<int,int> u = q.front();
        q.pop();
        if(vis[u.first]) continue;
        prev[u.first] = u.second;
        vis[u.first] = 1;
        for(auto a: g[u.first]){
            q.push({a, u.first});
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    int a,b;
    vector<vi> g(n);
    vi vis(n);
    vi prev(n, -1);
    f(0,m,1){
        cin>>a>>b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs(g,vis,prev);
    if(vis[n-1]==0){
        cout<<"IMPOSSIBLE";
        return;
    }
    int curr = n-1;
    vi path;
    while(curr!=0){
        path.push_back(curr);
        curr = prev[curr];
    }
    path.push_back(0);
    cout<<path.size()<<"\n";
    for(int i=path.size()-1; i>=0; i--){
        cout<<path[i]+1<<" ";
    }
}

int main(){
    // int t;
    // cin>>t;
    // f(0, t, 1){
        solve();
    // }
}