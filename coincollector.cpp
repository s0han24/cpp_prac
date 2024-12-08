#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>

using namespace std;

vector<int> roots;
vector<int> DAG_nodes;
vector<ll> sums;
vector<int> coins;
vector<vector<int>> DAG;
vector<set<int>> components;

void dfs1(vector<vector<int>> &graph, vector<bool> &visited, stack<int> &s, int u)
{
    if (visited[u])
        return;
    visited[u] = true;
    for (int v : graph[u])
    {
        dfs1(graph, visited, s, v);
    }
    s.push(u);
}

void dfs2(vector<vector<int>> &graph, vector<bool> &visited, int u, set<int> &comp)
{
    if (visited[u])
        return;
    visited[u] = true;
    comp.insert(u);
    for (int v : graph[u])
    {
        dfs2(graph, visited, v, comp);
    }
}

void kosaraju(vector<vector<int>> &graph, vector<vector<int>> &rev_graph)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        dfs1(graph, visited, s, i);
    }
    visited.assign(n, false);
    int root;
    ll sum = 0;
    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        if (visited[u])
            continue;
        components.push_back(set<int>());
        dfs2(rev_graph, visited, u, components.back());
        root = *components.back().begin();
        sum = 0;
        for (int u : components.back())
        {
            roots[u] = root;
            sum += coins[u];
        }
        sums[root] = sum;
        DAG_nodes.push_back(root);
    }
}

int topoSort(int u, vector<vector<int>> &g, vector<int> &visited, vector<int> &TopoSort)
{
    if (visited[u] == 1)
        return 0;
    visited[u] = 1;
    int res;
    for (auto v : g[u])
    {
        res = topoSort(v, g, visited, TopoSort);
    }
    if (u == roots[u])
        TopoSort.push_back(u);
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;

    roots.assign(n, -1);
    sums.assign(n, 0);
    coins.assign(n, 0);
    DAG.assign(n, vector<int>());

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    vector<vector<int>> g(n), gt(n);
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        gt[b].push_back(a);
    }

    kosaraju(g, gt);

    vector<int> TopoSort, visited(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            topoSort(i, g, visited, TopoSort);
    }
    reverse(TopoSort.begin(), TopoSort.end());
    ll dp[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = sums[i];
    }
    for (int v = 0; v < n; v++)
    {
        for (auto u : g[v])
        {
            int root_v = roots[v],
                root_u = roots[u];

            if (root_u != root_v)
                DAG[root_v].push_back(root_u);
        }
    }

    for (auto v : TopoSort)
    {
        for (auto u : DAG[v])
        {
            u = roots[u];
            dp[u] = max({dp[u], dp[v] + sums[u]});
        }
    }
    ll ans = 0;
    for (auto v : TopoSort)
    {
        ans = max({ans, dp[v]});
    }
    cout << ans;
    return 0;
}