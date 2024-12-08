#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
#define all(x) x.begin(), x.end()
#define ll long long
#define pll pair<ll, ll>
#define f(l, r, k) for (long long i = l; i < r; i += k)
#define fastio                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(nullptr);
#define vi vector<int>
#define vl vector<long long>
#define N 1000007
#define pb push_back
const ll INF = 1e9 + 7;
const ll mod = 1e9 + 7;

using namespace std;



void solve() {
    fastio;
    ll n, m;
    cin >> n >> m;
    vector<pll> alt(m);
    f(0, m, 1) { cin >> alt[i].first >> alt[i].second; }
    f(0, m, 1) { alt[i] = {alt[i].first, -alt[i].second}; }
    sort(all(alt));
    f(0, m, 1) { alt[i] = {alt[i].first, -alt[i].second}; }

    if (m == 0) {
        f(0, n - 1, 1) { cout << "1"; }
        cout << "\n";
        return;
    }

    vi del(m);

    f(1, m, 1) {
        if (alt[i].second < alt[i - 1].second) {
            del[i] = 1;
        }
    }
    ll k=0;
    while (del[k]) {
        k++;
    }

    f(0, alt[k].first, 1) { cout << "1"; }
    ll j = alt[k].first;
    f(0, m, 1) {
        if (del[i])
            continue;
        while (alt[i].second - j - 1 > alt[i].first) {
            cout << "0";
            j++;
        }
        while (j < alt[i].second - 1) {
            cout << "1";
            j++;
        }
    }
    while (j < n - 1) {
        cout << "1";
        j++;
    }
    cout << "\n";
}

int main() {
    fastio;
    int t;
    cin >> t;
    f(0, t, 1) { solve(); }
    // solve();
    return 0;
}