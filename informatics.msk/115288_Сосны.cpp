#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<ll, ll>;
// using lll = __int128_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
#ifdef ARCHL
    // freopen("B.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll cnt = 0, c = 0, idx;
    for (ll i = 0; i <= n; ++i) {   
        if (s[i] == 'A') {
            ++cnt;
        }
    }
    for (ll i = 0; i <= n; ++i) {
        if (s[i] == 'A') {
            ++c;
        }
        if (c == cnt / 2) {
            idx = i + 1;
        }
    }
    // cout << idx << '\n';
    vector<ll> ans(n + 1);
    for (ll i = 0; i < n + 1; ++i) {
        ans[i] = i + 1;
    }
    reverse(ans.begin() + idx, ans.end());
    for (auto &el : ans) {
        cout << el << ' ';
    }
    cout << '\n';
    return 0;
}