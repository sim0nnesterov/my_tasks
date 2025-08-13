#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string t, s;
    cin >> t >> s;
    vector<vector<ll>> v(s.size() + 1, vector<ll>(26, -1));
    vector<ll> suff(s.size() + 1, 0);
    for (ll i = 0; i < 26; ++i) {
        v[0][i] = 0;
        if (i == s[0] - 'a') {
            ++v[0][i];
        }
    }
    s = '_' + s;
    for (ll i = 1; i < s.size(); ++i) {
        if (i != 1) suff[i] = v[suff[i - 1]][s[i] - 'a'];
        for (ll j = 0; j < 26; ++j) {
            v[i][j] = v[suff[i]][j];
        }  
        if (i != s.size() - 1) v[i][s[i + 1] - 'a'] = i + 1; 
    }
    cout << '\n';
    ll ans = 0, idx = 0, i = 0;
    for (auto &el : t) {
        ++i;
        idx = v[idx][el - 'a'];
        if (idx == s.size() - 1) cout << i - s.size() + 1 << '\n';
    }
    return 0;
}