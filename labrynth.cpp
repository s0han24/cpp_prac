#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
#define f(l, r, k) for(int i=l; i<r; i+=k)
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define vi vector<int>
#define vl vector<long long>

using namespace std;

bool check(int x, int y, int n, int m){
    return x>=0 && x<n && y>=0 && y<m;
}

void bfs(vector<vector<char>> &g, pair<int,int> start, vector<vi> &prev, vector<vi> &vis){
    queue<tuple<int,int, int>> q;
    q.push({start.first, start.second, -1});
    while(q.size()>0){
        tuple<int,int,int> u = q.front();
        q.pop();
        if(vis[get<0>(u)][get<1>(u)]) continue;
        vis[get<0>(u)][get<1>(u)] = 1;
        prev[get<0>(u)][get<1>(u)] = get<2>(u);
        if(g[get<0>(u)][get<1>(u)]=='B') return;

        if(check(get<0>(u)-1, get<1>(u), g.size(), g[0].size()) && g[get<0>(u)-1][get<1>(u)] != '#') q.push({get<0>(u)-1, get<1>(u), 0});
        if(check(get<0>(u), get<1>(u)-1, g.size(), g[0].size()) && g[get<0>(u)][get<1>(u)-1] != '#') q.push({get<0>(u), get<1>(u)-1, 1});
        if(check(get<0>(u)+1, get<1>(u), g.size(), g[0].size()) && g[get<0>(u)+1][get<1>(u)] != '#') q.push({get<0>(u)+1, get<1>(u), 2});
        if(check(get<0>(u), get<1>(u)+1, g.size(), g[0].size()) && g[get<0>(u)][get<1>(u)+1] != '#') q.push({get<0>(u), get<1>(u)+1, 3});
    }
}

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
char p[] = {'U', 'L', 'D', 'R'};


void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> g(n, vector<char>(m));
    pair<int,int> start = {-1, -1}, end = {-1,-1};
    f(0,n,1){
        for(int j=0; j<m; j++){
            cin>>g[i][j];
            if(g[i][j]=='A')  start = {i,j};
            if(g[i][j]=='B')  end = {i,j};
        }
    }
    vector<vi> prev(n, vi(m, -1));
    vector<vi> vis(n, vi(m));
    bfs(g, start, prev, vis);
    if(vis[end.first][end.second]) cout<<"YES\n";
    else{
        cout<<"NO";
        return;
    }
    vector<char> path;
    char c = 'B';
    pair<int,int> curr = end;
    while(c!='A'){
        path.push_back(p[prev[curr.first][curr.second]]);
        curr = {curr.first - dx[prev[curr.first][curr.second]], curr.second - dy[prev[curr.first][curr.second]]};
        c = g[curr.first][curr.second];
    }
    cout<<path.size()<<"\n";
    for(int i= path.size()-1; i>=0; i--){
        cout<<path[i];
    }
}

int main(){
    int t=1;
    // cin>>t;
    f(0, t, 1){
        solve();
    }
}