
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<ll, ll>;
// using lll = __int128_t;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
#ifdef ARCH_Sim0n
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    ll n = s.size();
    vector<vector<pair<ll, string>>> dp(n, vector<pair<ll, string>>(n, {0, ""}));
    for (ll i = 0; i < n; ++i) {
        dp[i][i].first = 1;
        dp[i][i].second = string(1, s[i]);
    }
    for (ll i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1].first = 2;
            dp[i][i + 1].second = string(1, s[i]) + string(1, s[i + 1]);
        } else {
            dp[i][i + 1].first = 1;
            dp[i][i + 1].second = string(1, s[i]);
        }
    }
    for (ll l = 3; l <= n; ++l) {
        for (ll i = 0; i <= n - l; ++i) {
            ll j = i + l - 1;
            if (s[i] == s[j]) {
                dp[i][j].first = dp[i + 1][j - 1].first + 2;
                dp[i][j].second = string(1, s[i]) + dp[i + 1][j - 1].second + string(1, s[j]);
            } else {
                if (dp[i][j - 1].first >= dp[i + 1][j].first) {
                    dp[i][j] = dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
    }
    cout << dp[0][n - 1].first << '\n' << dp[0][n - 1].second << '\n';
    return 0;
}