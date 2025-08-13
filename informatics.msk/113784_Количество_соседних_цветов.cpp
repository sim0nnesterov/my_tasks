#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll B = 450;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, q;
    cin >> n >> m >> q;
    vector<ll> color(n + 1);
    vector<vector<ll>> g(n + 1);
    vector<bool> h(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> color[i];
    }
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> h_l;
    for (ll v = 1; v <= n; ++v) {
        if (g[v].size() >= B) {
            h[v] = true;
            h_l.push_back(v);
        }
    }
    vector<vector<ll>> cnt1(n + 1);
    vector<ll> cnt2(n + 1, 0);
    for (ll v : h_l) {
        cnt1[v].resize(n + 1, 0);
        for (ll u : g[v]) {
            ll c = color[u];
            if (cnt1[v][c]++ == 0) {
                cnt2[v]++;
            }
        }
    }
    while (q--) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll v, c;
            cin >> v >> c;
            ll buf = color[v];
            if (buf == c) continue;
            color[v] = c;
            for (ll u : g[v]) {
                if (h[u]) {
                    if (--cnt1[u][buf] == 0) {
                        cnt2[u]--;
                    }
                    if (cnt1[u][c]++ == 0) {
                        cnt2[u]++;
                    }
                }
            }
        } else {
            ll v;
            cin >> v;
            if (h[v]) {
                cout << cnt2[v] << '\n';
            } else {
                vector<bool> used(n + 1, false);
                ll ans = 0;
                for (ll u : g[v]) {
                    ll c = color[u];
                    if (!used[c]) {
                        used[c] = true;
                        ans++;
                    }
                }
                cout << ans << '\n';
            }
        }
    }
    return 0;
}