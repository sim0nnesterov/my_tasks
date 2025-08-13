
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<ll, ll>;
// using lll = __int128_t;

const ll MAXN = 1e18;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll K = 350;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
#ifdef ARCH_Sim0n
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    string s, ans;
    cin >> s;
    ans.assign(s.size(), '0');
    vector<ll> v(s.size(), 0);
    ll sz = s.size();
    v[sz - 1] = 1;
    for (ll i = sz - 2; i >= 0; --i) {
        v[i] = (s[i] == s[i + 1] ? v[i + 1] + 1 : 1);
    }
    ll ans_sz = 1, aidx = 0;
    for (ll i = 0; i < sz; ++i) {
        ll idx = i;
        for (ll j = 1; j + idx <= sz; idx += j, ++j) {
            if (v[idx] < j) {
                break;
            }
        }
        if (idx - i > ans_sz) {
            ans_sz = idx - i;
            aidx = i;
        }
    }
    for (ll i = aidx; i < aidx + ans_sz; ++i) {
        ans[i - aidx] = s[i];
    }
    for (auto &c : ans) {
        if (c != '0') {
            cout << c;
        }
    }
    return 0;
}   