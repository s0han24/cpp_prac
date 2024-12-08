#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
#define f(l, r, k) for(ll i=l; i<r; i+=k)
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define vi vector<ll>

using namespace std;

ll search(vi &v, ll l, ll r, ll u, ll dec){
    if(l==r) return r;
    ll mid = l + (r-l+1)/2;
    if(v[mid] - dec > u){
        return search(v, l, mid-1, u, dec);
    }else{
        return search(v, mid, r, u, dec);
    }
}

void solve(){
    fastio
    ll n;
    cin>>n;
    vi a(n);
    vi pre(n+1);
    pre[0] = 0;
    f(0,n,1){
        cin>>a[i];
        pre[i+1] = pre[i] + a[i];
    }
    ll q;
    cin>>q;
    ll l, u;
    f(0,q,1){
        cin>>l>>u;
        ll k = search(pre, l, n, u, pre[l-1]);
        while(k<n){
            if((pre[k+1]-pre[l-1]+1)*(2*u+1-pre[k+1]+pre[l-1]) < (pre[k]-pre[l-1]+1)*(2*u+1-pre[k]+pre[l-1])) break;
            k++;
        }
        cout<<k<<" ";
    }
    cout<<"\n";
}

int main(){
    fastio
    ll t;
    cin>>t;
    f(0, t, 1){
        solve();
    }
}