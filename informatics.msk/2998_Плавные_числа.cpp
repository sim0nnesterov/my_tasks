#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const ll INF = 1e9;
const ld RAM = 1e-9;
const int MOD = 1e7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<ll>> dp(n + 1, vector<ll> (10, 0));
    dp[1][0] = 0, dp[1][1] = 1, dp[1][2] = 1, dp[1][3] = 1, dp[1][4] = 1, dp[1][5] = 1, dp[1][6] = 1, dp[1][7] = 1, dp[1][8] = 1, dp[1][9] = 1;
    for (int i = 2; i <= n; i++){
        for (int j = 0; j <= 9; j++){
            if(j == 0) dp[i][j] = dp[i - 1][j] + dp[i - 1][j + 1];
            else if(j == 9) dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            else dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1];
        }
    }
    cout << dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4] + dp[n][5] + dp[n][6] + dp[n][7] + dp[n][8] +  dp[n][9] << '\n';
    return 0;
}          
