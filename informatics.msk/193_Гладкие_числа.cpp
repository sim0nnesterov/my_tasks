#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> dp(100, vector<ll> (10, 0));
    dp[0].assign(10, 1);
    for (ll i = 1; i < 100; ++i) {
        for (ll j = 0; j < 10; ++j) {
            for (ll k = j; k < 10; ++k) {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }
    ll len = 0, cnt = 0, idx = 1;
    while (cnt < n) {
        ++len;
        cnt += dp[len][1];
    }
    cnt -= dp[len][1];
    cnt = n - cnt;
    string ans = "";
    for (ll i = 0; i < len; ++i) {
        for (ll j = idx; j < 10; ++j) {
            ll buf = len - i - 1;
            if (cnt <= dp[buf][j]) {
                ans += '0' + j;
                idx = j;
                break;
            } else {
                cnt -= dp[buf][j];
            }
        }
    }
    cout << ans << '\n';
    return 0;   
}