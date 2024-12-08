#include <bits/stdc++.h>
#include <climits>
#define ll long long
#define f(l, r, k) for(long long i=l; i<r; i+=k)
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define vi vector<int>
#define vl vector<long long>
#define N 500007
#define mod 1000000007

using namespace std;

vector<vector<int>> adj;
vi vis,a;
ll n;

ll dfs(int x, int y, ll curr, int i){
    if(x==y) return curr+a[x]^i;
    vis[x] = true;
    ll res=0;
    for(auto j:adj[x]){
        if(!vis[j]){
            res = dfs(j, y, curr+a[x]^i, i+1);
            if(res!=-1) return res;
        }
    }
    return -1;
}

void solve(){
    fastio
    cin>>n;
    ll s, e;
    adj.assign(n+1, vi());
    
    f(0,n-1,1){
        cin>>s>>e;
        adj[s].push_back((e));
        adj[e].push_back((e));
    }
    a.assign(n+1,0);
    f(1,n+1,1){cin>>a[i];}
    ll q;
    cin>>q;
    ll x,y, lca_xy;
    f(0,q,1){
        cin>>x>>y;
        vis.assign(n+1, false);
        cout<<dfs(x,y,0, 0)<<"\n";
    }
}

int main(){
    fastio
    int t;
    cin>>t;
    f(0, t, 1){
        solve();
    }
    // solve();
    return 0;
}

