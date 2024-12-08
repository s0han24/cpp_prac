#include <bits/stdc++.h>
#define ll long long
#define INF LLONG_MAX
using namespace std;

vector<int> compn, comp1, comp1r;

// Bellman-Ford algorithm
// Complexity: O(n * m)
// d: vector to store the shortest path from the source to each vertex
// return -1 if there is a negative cycle, otherwise the node that was last updated
int bellmanFord(vector<vector<pair<int, int>>> &g, vector<ll> &d)
{
    int n = g.size();
    d[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int u = 0; u < n; u++)
        {
            if(d[u] == INF) continue;
            for (auto v : g[u])
            {
                // d[v.second] = min({d[v.second], d[u] + v.first});
                if (d[v.second] == INF|| d[u] + v.first < d[v.second])
                {
                    d[v.second] = d[u] + v.first;
                }
            }
        }
    }
    
    for (int u = 0; u < n; u++)
    {
        for (auto v : g[u])
        {
            if (d[u] + v.first < d[v.second])
            {
                if (comp1[v.second] && compn[v.second])
                    return 1;
                d[v.second] = d[u] + v.first;
            }
        }
    }
    return 0;
}

void dfs(int v, vector<vector<pair<int, int>>> &g, vector<int> &vis)
{
    if (vis[v])
        return;
    vis[v] = 1;
    for (auto u : g[v])
        dfs(u.second, g, vis);
}

int main()
{
    int n, m, a, b, x;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    vector<vector<pair<int, int>>> gt(n);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> x;
        a--;
        b--;
        g[a].push_back({-x, b});
        gt[b].push_back({-x, a});
    }
    comp1.assign(n, 0);
    comp1r.assign(n, 0);
    compn.assign(n, 0);
    dfs(0, g, comp1);
    dfs(0, gt, comp1r);
    dfs(n - 1, gt, compn);
    vector<ll> d(n, INF);
    int res = bellmanFord(g, d);
    if (res)
        cout << "-1";
    else
    {
        cout << -d[n - 1];
    }
    return 0;
}