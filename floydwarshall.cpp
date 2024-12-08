#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<ll>> dist(n, vector<ll>(n,LLONG_MAX));
    for(int i=0;i<n;i++){
        dist[i][i] = 0;
    }
    ll a,b,c;
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        a--;b--;
        dist[a][b] = min({dist[a][b],c});
        dist[b][a] = min({dist[b][a],c});
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(dist[j][i] != LLONG_MAX && dist[i][k] != LLONG_MAX){
                    dist[j][k] = min({dist[j][k], dist[j][i] + dist[i][k]});
                }
            }
        }
    }
    for(int i=0;i<q;i++){
        cin >> a >> b;
        a--;b--;
        if(dist[a][b] == LLONG_MAX){
            cout << -1 << endl;
        }else{
            cout << dist[a][b] << endl;
        }
    }
    return 0;
}