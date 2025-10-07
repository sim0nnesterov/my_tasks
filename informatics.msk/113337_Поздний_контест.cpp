#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<ll>> g, dp;
vector<ll> ct, cm;

void dfs1(ll v, ll p) {
    dp[v][0] = 0;
    dp[v][1] = ct[v];
    for (auto &u : g[v]) {
        if (u != p) {
            dfs1(u, v);
            dp[v][0] += dp[u][1];
            dp[v][1] += min(dp[u][0], dp[u][1]);
        }
    }
}

void dfs2(ll v, ll p, ll fl) {
    if (fl) {
        cm.push_back(v);
        for (auto &u : g[v]) {
            if (u != p) {
                dfs2(u, v, dp[u][0] > dp[u][1]);
            }
        }
    } else {
        for (auto &u : g[v]) {
            if (u != p) {
                dfs2(u, v, 1);
            }
        }
    }
}

int main() {
    ll n;
    cin >> n;
    g.assign(n, {});
    dp.assign(n, vector<ll>(2));
    ct.assign(n, 0);
    for (ll i = 0; i < n - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    for (ll i = 0; i < n; ++i) {
        cin >> ct[i];
    }
    if (n == 1) {
        cout << ct[0] << " 1\n1\n";
        return 0;
    }
    dfs1(0, -1);
    ll ans = min(dp[0][0], dp[0][1]), fl = dp[0][0] >= dp[0][1];
    dfs2(0, -1, fl);
    sort(cm.begin(), cm.end());
    cout << ans << ' ' << cm.size() << '\n';
    for (auto &el : cm) {
        cout << el + 1 << ' ';
    }
    cout << '\n';
    return 0;
}