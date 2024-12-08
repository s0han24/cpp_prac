#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
#define f(l, r, k) for(int i=l; i<r; i+=k)
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define vi vector<int>

using namespace std;

void solve(){
    fastio
    int n;
    cin>>n;
    vi v(n);
    vi prefix(n);
    prefix[0] = -1;
    cin>>v[0];
    f(1,n,1){
        cin>>v[i];
        if(v[i]!=v[i-1]){
            prefix[i] = i-1;
        }else{
            prefix[i] = prefix[i-1];
        }
    }
    int q;
    cin>>q;
    f(0,q,1){
        int l, r;
        cin>>l>>r;
        if(prefix[r-1] >= l-1){
            cout<< prefix[r-1]+1 <<" "<< r <<"\n";
        }else{
            cout<<"-1 -1\n";
        }
    }
    cout<<"\n";
}

int main(){
    fastio
    int t;
    cin>>t;
    f(0, t, 1){
        solve();
    }
}