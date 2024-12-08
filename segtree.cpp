#include <bits/stdc++.h>
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

vl tree;
ll n;

// querying tree
ll query(ll query_low, ll query_high, ll node_low, ll node_high, ll node) {
    if (query_low <= node_low && query_high >= node_high) {
        return tree[node];
    }
    if (query_high < node_low || query_low > node_high) {
        return 0;
    }
    ll half = node_low + (node_high - node_low) / 2;
    return query(query_low, query_high, node_low, half, 2 * node) +
           query(query_low, query_high, half + 1, node_high, 2 * node + 1);
}

// updates
void update(ll new_val, ll i) {
    tree[n + i] = new_val;
    for (ll j = (n + i) / 2; j >= 1; j /= 2) {
        tree[j] = tree[2 * j] + tree[2 * j + 1];
    }
}

void solve() {
    fastio;
    ll q;
    cin >> n >> q;
    ll old_n = n;

    while (n & (n - 1)) {
        n++;
    }

    vl x(n);
    f(0, old_n, 1) { cin >> x[i]; }

    // building tree
    tree.resize(2 * n);
    f(n, 2 * n, 1) { tree[i] = x[i - n]; }
    for (ll i = n - 1; i >= 1; i--) {
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    ll a, b;
    int c;
    while (q--) {
        cin >> c >> a >> b;
        if(c==2){
            a--;
            b--;
            cout << query(a, b, 0, n - 1, 1) << "\n";
        } else {
            update(b, a-1);
        }
    }
}

int main() {
    fastio;
    // int t;
    // cin >> t;
    // f(0, t, 1) { solve(); }
    solve();
    return 0;
}