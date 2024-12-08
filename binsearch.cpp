#include <bits/stdc++.h>
#define ll long long

ll binsearch(std::vector<ll> &v, ll x){ // l = 0 and r = n-1 at the start
    ll m;
    ll l = 0, r = v.size()-1;
    while(l<=r){
        m = l + (r-l)/2;
        if(v[m] == x) return m;
        else if(v[m] < x) l = m+1;
        else r = m-1;
    }
    return -1;
}

ll lowerBound(std::vector<ll> &v, ll x){
    ll l = 0, r = v.size()-1, m;
    while(l<r){
        m = l + (r-l)/2;
        if(v[m] < x) l = m+1;
        else r = m;
    }
    return l;
}