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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    ll n = s.size();
    vector<pii> dp(n + 1, {INF, INF});
    dp[0] = {0, 1};
    for (ll i = 1; i <= n; ++i) {
        dp[i] = {dp[i - 1].first + (s[i - 1] == 'L' || s[i - 1] == 'B'), dp[i - 1].second + (s[i - 1] == 'R' || s[i - 1] == 'B')};
        ll mn = min(dp[i].first, dp[i].second);
        dp[i] = {dp[i].first == mn ? mn : mn + 1, dp[i].second == mn ? mn : mn + 1};
    }
    cout << dp[n].second << '\n';
    return 0;
}