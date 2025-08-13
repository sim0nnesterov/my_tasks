
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

vector<ll> a;

bool check(ll n, ll mid) {
    map<ll, ll> mp;
    for (ll i = 1; i < n; ++i) {
        if (a[i] <= a[i - 1]) { 
            while (!mp.empty() && mp.rbegin()->first > a[i]) {
                mp.erase(mp.rbegin()->first);
            }
            ll idx = a[i];
            while (idx > 0) {
                if (mp[idx] + 1 < mid) {
                    ++mp[idx];
                    break;
                } else {
                    mp.erase(idx);
                    --idx;
                }
            }
            if (idx <= 0) {
                return 0;
            }
        }
    }
    return 1;
}

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
    a.assign(n, 0);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    bool fl = false;
    for (ll i = 0; i < n - 1; ++i) {
        if (a[i] >= a[i + 1]) {
            fl = true;
        }
    }
    if (!fl) {
        cout << "1\n";
        return 0;
    } 
    ll l = 1, r = n, mid;
    vector<pii> v(n);
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (check(n, mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << '\n';
    return 0;
}