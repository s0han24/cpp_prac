#include <bits/stdc++.h>
#define vi vector<int>
#define MAXD 30

using namespace std;

int parent[200007][MAXD];

int jump(int x, int k){
    for(int i=0; i<MAXD; i++){
        if(k & (1<<i)) x = parent[x][i];
    }
    return x;
}

int main(){
    ios_base::sync_with_stdio(false);

	cin.tie(NULL);

    int n,q;
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>parent[i][0];
    }
    for(int j=1; j<MAXD; j++){
        for(int i=1; i<=n; i++){
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }
    int x, s;
    for(int i=0; i<q; i++){
        cin>>x>>s;
        cout<<jump(x,s)<<'\n';
    }
    return 0;
}