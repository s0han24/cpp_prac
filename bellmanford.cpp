#include <bits/stdc++.h>
#define ll long long
#define INF 1ll<<42
using namespace std;

// Bellman-Ford algorithm
// Complexity: O(n * m)
// d: vector to store the shortest path from the source to each vertex
// return -1 if there is a negative cycle, otherwise the node that was last updated
int bellmanFord(vector<vector<pair<int, int>>> &g, vector<ll> &d, vector<int> &p){
    int n = g.size();
    d[0] = 0;
    for(int i = 0; i < n - 1; i++){
        for(int u = 0; u < n; u++){
            if(d[u] == INF) continue;
            for(auto v : g[u]){
                // d[v.second] = min({d[v.second], d[u] + v.first});
                if(d[v.second] == INF || d[u] + v.first < d[v.second]){
                    d[v.second] = d[u] + v.first;
                    p[v.second] = u;
                }
            }
        }
    }
    int res = -1;
    for(int u = 0; u < n; u++){
        for(auto v : g[u]){
            if(d[u] + v.first < d[v.second]){
                d[v.second] = d[u] + v.first;
                p[v.second] = u;
                res = v.second;
            }
        }
    }
    return res;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        g[a].push_back({c,b});
    }
    vector<ll> d(n, INF);
    vector<int> p(n, -1);
    int res = bellmanFord(g, d, p);
    if(res == -1){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        unordered_set<int> s;
        vector<int> cycle;
        cycle.push_back(res);
        s.insert(res);
        int curr = p[res];
        while(s.count(curr) == 0){
            cycle.push_back(curr);
            s.insert(curr);
            curr = p[curr];
        }
        cycle.push_back(curr);
        unordered_set<int> final;
        for(auto i = cycle.rbegin(); i<cycle.rend(); i++){
            if(final.count(*i) != 0){
                cout<<*i+1<<" ";
                break;
            }
            final.insert(*i);
            cout<<*i+1<<" ";
        }

    }
    return 0;
}