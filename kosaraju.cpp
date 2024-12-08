#include <bits/stdc++.h>

using namespace std;

void dfs1(vector<vector<int>> &graph, vector<bool> &visited, stack<int> &s, int u){
    if(visited[u]) return;
    visited[u] = true;
    for(int v : graph[u]){
        dfs1(graph, visited, s, v);
    }
    s.push(u);
}

void dfs2(vector<vector<int>> &graph, vector<bool> &visited, int u, vector<int> &comp){
    if(visited[u]) return;
    visited[u] = true;
    comp.push_back(u);
    for(int v : graph[u]){
        dfs2(graph, visited, v, comp);
    }
}

vector<vector<int>> kosaraju(vector<vector<int>> &graph, vector<vector<int>> &rev_graph){
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> s;
    for(int i = 0; i < n; i++){
        dfs1(graph, visited, s, i);
    }
    visited.assign(n, false);
    vector<vector<int>> components;
    while(!s.empty()){
        int u = s.top();
        s.pop();
        if(visited[u]) continue;
        components.push_back(vector<int>());
        dfs2(rev_graph, visited, u, components.back());
    }
    return components;
}

int main(){
    return 0;
}