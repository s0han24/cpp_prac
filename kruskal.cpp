#include <bits/stdc++.h>
#define ll long long
#define MAX_SIZE 100007
#define swap(x, y)                                                             \
    x = x ^ y;                                                                 \
    y = x ^ y;                                                                 \
    x = x ^ y;
#define fastio                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(nullptr);
#define vi vector<int>
#define vl vector<long long>

using namespace std;

ll linked[MAX_SIZE];
ll sizeOf[MAX_SIZE];

ll find(ll x){
    while(x != linked[x]) x = linked[x];
    return x;
}

bool same(ll a, ll b){
    return find(a) == find(b);
}

void unite(ll a, ll b){
    a = find(a);
    b = find(b);
    if(sizeOf[a] < sizeOf[b]){swap(a,b);}
    sizeOf[a] += sizeOf[b];
    linked[b] = a;
}

ll kruskal(vector<pair<pair<ll, ll>, ll>> edges, ll n){
    ll res=0;
    sort(edges.begin(), edges.end(), [](pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b){
        return a.second < b.second;
    });
    for(ll i = 0; i < n; i++){
        linked[i] = i;
        sizeOf[i] = 1;
    }
    for(ll i = 0; i < edges.size(); i++){
        if(!same(edges[i].first.first, edges[i].first.second)){
            unite(edges[i].first.first, edges[i].first.second);
            res+=edges[i].second;
        }
    }
    return res;
}

void dfs(vector<vector<pair<int,int>>> &g, vector<int> &vis, int v){
    if(vis[v]) return;
    vis[v]=1;
    for(auto u: g[v]){
        dfs(g,vis,u.second);
    }
}

void solve(){
    // cin >> n >> m;
    // vector<pair<pair<ll, ll>, ll>> edges(m);
    // vector<vector<pair<int,int>>> g(n);
    // int a,b,w;
    // for(ll i = 0; i < m; i++){
    //     cin >> a >> b >> w;
    //     a--; b--;
    //     edges[i] = {{a,b}, w};
    //     g[a].push_back({w, b});
    //     g[b].push_back({w, a});
    // }
    // vector<int> vis(n);
    // dfs(g,vis,0);
    // for(int i=0; i<n; i++){
    //     if(!vis[i]){
    //         cout<<"IMPOSSIBLE";
    //         return;
    //     }
    // }
    // cout<<kruskal(edges, n);

    ll n;
    cin >> n;
    vl x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vl a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    

    vector<pair<pair<ll, ll>, ll>> edges();

}

int main() {
    ll t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}