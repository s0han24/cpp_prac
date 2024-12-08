#include <bits/stdc++.h>
#define ll long long int
#define INF -1

using namespace std;

// works for directed graphs
void dijkstra_using_set(vector<vector<pair<int, int>>> &g, vector<ll> &d, int v)
{
    set<pair<ll, ll>> s;
    vector<int> known(g.size());
    for (int i = 0; i < (int)g.size(); i++)
        d[i] = INF;
    d[v] = 0;
    s.insert({0, v});
    while (!s.empty())
    {
        int u = (*(s.begin())).second;
        s.erase(s.begin());
        if (known[u])
            continue;
        known[u] = true;
        for (auto i : g[u])
        {
            if (d[i.second] == INF || d[i.second] > d[u] + i.first)
            {
                s.erase({d[i.second], i.second}); // to update the value in the set, we need to remove the old value and insert the new one
                d[i.second] = d[u] + i.first;
                s.insert({d[i.second], i.second});
            }
        }
    }
}

int main()
{
    int n, m, a, b, w;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    vector<vector<pair<int, int>>> gt(n);
    vector<tuple<int, int, int>> e;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        a--;
        b--;
        g[a].push_back({w, b});
        gt[b].push_back({w, a});
        e.push_back({a, b, w});
    }
    vector<ll> d1(n), dn(n);
    dijkstra_using_set(g, d1, 0);
    dijkstra_using_set(gt, dn, n - 1);
    ll res = LLONG_MAX;
    ll curr1, curr2;
    for (auto edge : e)
    {
        curr1 = LLONG_MAX;
        curr2 = LLONG_MAX;
        if(get<0>(edge) == n-1){
            continue;
        }
        if (d1[get<0>(edge)] != INF && dn[get<1>(edge)] != INF)
        {
            curr1 = d1[get<0>(edge)] + dn[get<1>(edge)] + get<2>(edge) / 2;
        }
        res = min(min(curr1, curr2), res);
    }
    cout << res;
    return 0;
}