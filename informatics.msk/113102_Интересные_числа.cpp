
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<ll, ll>;
// using lll = __int128_t;

const ll MOD = 1e9 + 7;

ll cnt_m(string n) {
    if (n.empty()) return 0;
    vector<vector<ll>> dp(n.size() + 1, vector<ll>(10, 0));
    dp[1].assign(10, 1);
    dp[1][0] = 0;
    for (ll i = 2; i <= n.size(); ++i) {
        for (ll c = 1; c < 10; ++c) {
            for (ll _c = 9; _c >= c; --_c) {
                dp[i][c] += dp[i - 1][_c];
            }
            dp[i][c] %= MOD;
        }
    }
    // for (auto &vec : dp) {
    //     for (auto &el : vec) {
    //         cout << el << ' ';
    //     }
    //     cout << '\n';
    // }
    ll ans = 0;
    for (ll i = 1; i < n.size(); ++i) {
        for (ll c = 1; c < 10; ++c) {
            ans += dp[i][c];
        }
        ans %= MOD;
    }
    bool gd = 1;
    for (ll i = 0; i < n.size(); ++i) {
        if (i && n[i - 1] > n[i]) {
            gd = 0;
        }
        if (!gd) break;
        ll st = (i ? n[i - 1] - '0' : 1);
        for (ll c = st; c < n[i] - '0'; ++c) {
            ans += dp[n.size() - i][c];
        }
        ans %= MOD;
    }
    bool fl = 1;
    for (ll i = 0; i < n.size() - 1; ++i) {
        if (n[i] > n[i + 1]) {
            fl = 0;
        }
    }
    if (n == "0") {
        fl = 0;
    }
    return (ans + fl) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
#ifdef ARCH_Sim0n
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    string l, r;
    cin >> l >> r;
    if (l == "1") {
        l = "0";
    } else {
        reverse(l.begin(), l.end());
        for (ll i = 0; i < l.size(); ++i) {
            if (l[i] - '0') {
                --l[i];
                break;
            } else {
                l[i] = '9';
            }
        }
        if (l.back() == '0') {
            l.pop_back();
        }
        reverse(l.begin(), l.end());
    }
    cout << (cnt_m(r) - cnt_m(l) + MOD) % MOD << '\n';
    // cout << l << '\n';
    return 0;
}