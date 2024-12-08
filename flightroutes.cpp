#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    int n,m,k,a,b;
    ll c;
    cin>>n>>m>>k;
    vector<vector<pair<ll,ll>>> g(n);
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        a--;b--;
        g[a].push_back({c,b});
    }
    priority_queue<ll> kdists[n];
    priority_queue<pair<ll,ll>> p;
    p.push({0,0});
    while(!p.empty()){
        auto u = p.top();
        p.pop();
        u.first = -u.first;
        if(!kdists[u.second].empty() && (u.first) > kdists[u.second].top()) continue;
        for(auto v: g[u.second]){
            ll d = u.first + v.first;
            if(kdists[v.second].size() < k){
                kdists[v.second].push({d});
                p.push({-d,v.second});
            }else if(d < kdists[v.second].top()){
                kdists[v.second].pop();
                kdists[v.second].push({d});
                p.push({-d,v.second});
            }
        }
    }
    vector<ll> res;
    while(!kdists[n-1].empty()){
        res.push_back(kdists[n-1].top());
        kdists[n-1].pop();
    }
    for(auto it = res.rbegin(); it!=res.rend(); it++){
        cout<<*it<<" ";
    }
}