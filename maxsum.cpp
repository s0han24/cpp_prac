#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
#define f(l, r, k) for(int i=l; i<r; i+=k)
#define vi vector<int>
#define vl vector<long long>

using namespace std;

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    vi v(n);
    vi pre(n);
    priority_queue<pair<ll,ll>> h;
    ll sum = 0;
    f(0,n,1){
        cin>>v[i];
        sum+=v[i];
        pre[i] = sum;
        if(i-a>0) h.push(mp(pre[i-a], i-a));
        
    }

}

int main(){
    solve();
}