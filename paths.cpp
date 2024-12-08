#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
#define f(l, r, k) for(int i=l; i<r; i+=k)
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define vi vector<int>

using namespace std;

ll paths(vector<vector<char>> &v, int n, string &s, int i, int j){
    if(i==1 && j==n-1) return 1;
    if(v[i][j] != s[i+j]) return 0;
    ll curr = 0;
    if(j<n-1){
        curr += paths(v, n, s, i, j+1);
    }
    if(i==0){
        curr += paths(v, n, s, i+1, j);
    }
    return curr;
}

string mins(string &s1, string &s2){
    f(0,s1.size(),1){
        if(s1[i]<s2[i]) return s1;
        else if(s2[i]<s1[i]) return s2;
    }
    return s1;
}

string smallest(vector<vector<char>> &v, int n){
    vector<vector<string>> vs(2, vector<string>(n));
    vs[0][0] = string(1, v[0][0]);
    f(0,2,1){
        for(int j=0; j<n; j++){
            if(i==0 && j==0) continue;
            if(i>0 && j>0) vs[i][j] = mins(vs[i-1][j], vs[i][j-1]) + v[i][j];
            else if(i==0) vs[i][j] = vs[i][j-1] + v[i][j];
            else vs[i][j] = vs[i-1][j] + v[i][j];
        }
    }
    return vs[1][n-1];
}

void solve(){
    fastio
    int n;
    cin>>n;
    vector<vector<char>> grid(2, vector<char>(n));
    f(0,n,1){
        cin>>grid[0][i];
    }
    f(0,n,1){
        cin>>grid[1][i];
    }
    string s = smallest(grid,n);
    cout << s << "\n";
    cout << paths(grid, n, s, 0, 0) << "\n";
}

int main(){
    fastio
    int t;
    cin>>t;
    f(0, t, 1){
        solve();
    }
}