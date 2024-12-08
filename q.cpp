#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define vi vector<int>
#define vl vector<long long>

using namespace std;

// void SieveOfEratosthenes(int n) {
//     // Create a boolean array "prime[0..n]" and initialize
//     // all entries it as true. A value in prime[i] will
//     // finally be false if i is Not a prime, else true.
//     vector<bool> prime(n + 1, true);

//     for (int p = 2; p * p <= n; p++) {

//         // If prime[p] is not changed, then it is a prime
//         if (prime[p] == true) {
//             // Update all multiples of p greater than or
//             // equal to the square of it numbers which are
//             // multiple of p and are less than p^2 are
//             // already been marked.
//             for (int i = p * p; i <= n; i += p)
//                 prime[i] = false;
//         }
//     }
// }

void solve(){
    ll n, m, L;
    cin >> n >> m >> L;
    vl l(n), r(n);
    vl largest_now(n+1);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        largest_now[i+1] = max(largest_now[i], r[i]-l[i]);
    }

    set<pair<ll,ll>> s;
    ll x, v;
    ll k = 1;
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        cin >> x >> v;
        if()

        s.insert({v, x});

    }

    cout<<ans<<"\n";
}

int main(){
    fastio
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        solve();
    }
    return 0;
}