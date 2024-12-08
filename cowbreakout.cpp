#include <bits/stdc++.h>
#define ll long long
#define f(l, r, k) for(int i=l; i<r; i+=k)
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define vi vector<int>
#define vl vector<long long>

using namespace std;

void solve(){
    fastio
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    int n;
    cin>>n;
    vi a(n);
    f(0,n,1){ cin>>a[i]; }
    if(a[0]>0){ cout<<"-1"; return;}
    a[0] = 0;
    int log = -1;
    for(int i=n-1; i>0; i--){
        if(a[i]>=0 && log >=0 && log != a[i]){
            cout<<"-1";
            return;
        }else if(a[i]>=0){
            log = a[i];
        }else if(a[i]<0){
            a[i] = log;
        }
        if(log >= 0) log--;
    }
    int count1 = 0, count0 = 0;
    f(0, n, 1){
        if(a[i]==-1) count1++;
        if(a[i]==0) count0++;
    }
    cout<<count0<<" "<<count0+count1;
}

int main(){
        solve();
        return 0;
}