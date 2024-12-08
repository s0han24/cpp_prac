#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <type_traits>
#include <utility>
#include <vector>
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
    ll n;
    cin >> n;
    vl p(n);
    f(0, n, 1) { cin >> p[i]; }
    f(n / 2, n, 1) { cout << p[i] << " "; }
    f(0, n / 2, 1) { cout << p[i] << " "; }
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