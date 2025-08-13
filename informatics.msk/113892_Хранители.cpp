#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    // freopen("input.txt", "r", stdin);
    ll n;
    cin >> n;
    map<ll, ll> mpx;
    map<ll, ll> mpy;
    map<pair<ll, ll>, ll> mp; 
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ll s, t;
        cin >> s >> t;
        ans += mpx[s] + mpy[t] - mp[{s, t}];
        ++mpx[s];
        ++mpy[t];
        ++mp[{s, t}];
    }
    cout << ans << '\n';
    return 0;
}
