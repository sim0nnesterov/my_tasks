#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<ll, ll>;
// using lll = __int128_t;

// const ll MAXN = ;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-6;

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
    for (ll l = 2; l <= n; ++l) {
        for (ll i = 0; i <= n - l; ++i) {
            ll j = i + l - 1, ans = 0, sz = 0;
            string buf = "";
            char a = s[i], b = s[j];
            ll fl = 0;
            if ((a == '{' && b == '}') || (a == '(' && b == ')') || (a == '[' && b == ']')) {
                fl = 1;
            }
            if (fl) {
                sz = 2 + (i + 1 <= j - 1 ? dp[i + 1][j - 1].first : 0ll);
                if (sz > ans) {
                    ans = sz;
                    buf = a + dp[i + 1][j - 1].second + b;
                }
            }
            for (ll k = 1; k < j; ++k) {
                if (dp[i][k].first + dp[k + 1][j].first > ans) { 
                    ans = dp[i][k].first + dp[k + 1][j].first;
                    buf = dp[i][k].second + dp[k + 1][j].second;
                }
            }
            dp[i][j] = {ans, buf};
        }
    } 
    cout << dp[0][n - 1].second << '\n';
    return 0;
}