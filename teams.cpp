#include <bits/stdc++.h>
#define ll long long
#define f(l, r, k) for(int i=l; i<r; i+=k)
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define vi vector<int>
#define vl vector<long long>

using namespace std;

int gcolor(vector<vi> &g, vi &color, int v, int addColor){
    if(color[v] != 0 && color[v] != addColor) return 0;
    else if(color[v]!=0) return 1;
    color[v] = addColor;
    if(addColor == 1) addColor = 2;
    else addColor = 1;
    int res;
    for(auto a: g[v]){
        res = gcolor(g, color, a, addColor);
        if(res==0) return 0;
    }
    return 1;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vi> g(n);
    int a,b;
    f(0,m,1){
        cin>>a>>b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi color(n);
    int res;
    f(0,n,1){
        if(color[i]==0) res = gcolor(g,color,i, 1);
        if(res == 0){
            cout<<"IMPOSSIBLE";
            return;
        }
    }
    f(0,n,1){
        cout<<color[i]<<" ";
    }
}

int main(){
    // int t;
    // cin>>t;
    // f(0, t, 1){
        solve();
    // }
}