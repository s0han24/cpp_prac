#include <bits/stdc++.h>
#define ll long long
#define f(l, r, k) for(int i=l; i<r; i+=k)
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define vi vector<int>
#define vl vector<long long>

using namespace std;

void solve(){
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    vector<vi> g(n);
    int a,b;
    f(0, m, 1){
        cin>>a>>b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi colors(n);
    bool ok;
    for(int i=0; i<n; i++){
        for(int j=1; j<=4; j++){
            ok = true;
            for(int k=0; k<g[i].size(); k++){
                if(colors[g[i][k]] == j) ok = false;
            }
            if(ok == true){
                colors[i] = j;
                cout<<j;
                break;
            }
        }
    }
}

int main(){
    
        solve();
    
    return 0;
}