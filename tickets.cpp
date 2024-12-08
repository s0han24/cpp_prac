#include <bits/stdc++.h>
#define ll long long
#define f(l, r, k) for(int i=l; i<r; i+=k)
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define vi vector<int>
#define vl vector<long long>

using namespace std;

void solve(){
    ll n,m,k;
    cin>>n>>m>>k;

    vi a(n);
    f(0,n,1){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    ll cost = 0;
    ll i=0;
    while(i*m<=k-m){
        cost+= m*(a[i]+i*m);
        i++;
    }
    cost += (k-i*m)*(a[i]+i*m);
    cout<<cost<<endl;
}

int main(){
    fastio
    int t;
    cin>>t;
    f(0, t, 1){
        solve();
    }
    return 0;
}