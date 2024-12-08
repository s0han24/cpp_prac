#include <bits/stdc++.h>
#define INF -1
#define ll long long

using namespace std;

// most of this is from cph
// there will be multiple instances of a vertex in priority queue, but we only need the one with the smallest distance which will come out first
// to avoid this, we can use a set instead of a priority queue

// for directed graphs
void dijkstra(vector<vector<pair<int,int>>> &g, vector<ll> &d, int v){
    priority_queue<pair<ll,ll>> s;
    vector<int> known(g.size());
    for(int i=0; i<(int)g.size(); i++) d[i] = INF;
    d[v] = 0;
    s.push({0, v});
    while(!s.empty()){
        int u = s.top().second;
        s.pop();
        if(known[u]) continue; // this is not needed for set
        known[u] = true; // this is not needed for set
        for(auto i : g[u]){
            if(d[i.second] == INF || d[i.second] > d[u] + i.first){
                d[i.second] = d[u] + i.first;
                s.push({-d[i.second], i.second}); // priority queue gets max dist but we want min, hence the negative
            }
        }
    }
}

// for directed graphs
void dijkstra_using_set(vector<vector<pair<int,int>>> &g, vector<ll> &d, int v){
    set<pair<ll,ll>> s;
    vector<int> known(g.size());
    for(int i=0; i<(int)g.size(); i++) d[i] = INF;
    d[v] = 0;
    s.insert({0, v});
    while(!s.empty()){
        int u = (*(s.begin())).second;
        s.erase(s.begin());
        for(auto i : g[u]){
            if(d[i.second] == INF || d[i.second] > d[u] + i.first){
                s.erase({d[i.second], i.second}); // to update the value in the set, we need to remove the old value and insert the new one
                d[i.second] = d[u] + i.first;
                s.insert({d[i.second], i.second});
            }
        }
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
    }
    dijkstra_using_set(g, d, 0);
    for(int i=0; i<n; i++) cout << d[i] << " ";
    return 0;
}