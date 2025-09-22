
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
    ll n;
    cin >> n;
    vector<ld> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<ld>> dp(n + 1, vector<ld>(n + 1, 0));
    for (ll i = 1; i <= n; ++i) {
        dp[i][i] = a[i - 1];
    }
    for (ll i = 2; i <= n; ++i) {
        for (ll j = 1; j <= n - i + 1; ++j) {
            ll idx = j + i - 1;
            ld ans = 0.0;
            for (ll k = j; k < idx; ++k) {
                if ((dp[j][k] + dp[k + 1][idx]) / 2 > ans) {
                    ans = (dp[j][k] + dp[k + 1][idx]) / 2;
                }
            }
            dp[j][idx] = ans;
        }
    }
    cout << fixed << setprecision(7) << dp[1][n] << '\n';
    return 0;
}