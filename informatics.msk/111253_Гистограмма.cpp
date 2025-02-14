#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<ll, ll>;

const ll MAXN = 1e18;
const ll MOD = 1e9 + 7;

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
    vector<ll> v(n), pref(n), suf(n);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }
    deque<ll> dq;
    for (ll i = 0; i < n; ++i) {
        while (!dq.empty() && v[dq.back()] >= v[i]) {
            dq.pop_back();
        }
        pref[i] = (dq.empty() ? -1 : dq.back());
        dq.push_back(i);
    }
    dq.clear();
    for (ll i = v.size() - 1; i >= 0; --i) {
        while (!dq.empty() && v[dq.back()] >= v[i]) {
            dq.pop_back();
        }
        suf[i] = (dq.empty() ? n : dq.back());
        dq.push_back(i);
    }   
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ans = max(ans, (suf[i] - pref[i] - 1) * v[i]);
    }
    cout << ans << '\n';
    return 0;
}          