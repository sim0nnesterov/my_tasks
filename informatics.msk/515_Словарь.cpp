#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ld = long double; 
using pii = pair<int, int>;

const ll INF = 2 * 1e18;
const ld RAM = 1e-9;
const dbl EPS = 1e-7;
const int MOD = 1e7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //? freopen("input.txt", "r", stdin);
    //? freopen("output.txt", "w", stdout); 
    string s;
    cin >> s;
    int n;
    cin >> n;
    unordered_set<string> us;
    vector<int> dp(s.size() + 1, - 1);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        us.insert(x);
    }
    for (int i = 1; i <= s.size(); ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (dp[j] != -1 && us.count(s.substr(j, i - j))) {
                dp[i] = j;
                break; 
            }
        } 
    } 
    string ans;
    int i = s.size();
    while (i) {
        ans = s.substr(dp[i], i - dp[i]) + " " + ans;
        i = dp[i];
    }
    cout << ans << '\n';
    return 0;
}

//! OS: ArchLinux ~ notebook