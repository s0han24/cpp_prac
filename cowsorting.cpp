#include <bits/stdc++.h>
#define ll long long
#define f(l, r, k) for(int i=l; i<r; i+=k)
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define vi vector<int>
#define vl vector<long long>

using namespace std;

void solve(){
    int n;
    ifstream fin("sleepy.in");
	ofstream fout("sleepy.out");
    fin>>n;
    vi p(n);
    f(0,n,1){ fin>>p[i]; }
    int i;
    for(i=n-2; i>=0; i--){
        if(p[i] > p[i+1]){ break; }
    }
    fout<<i+1;
}

int main(){
    
        solve();
        return 0;
}