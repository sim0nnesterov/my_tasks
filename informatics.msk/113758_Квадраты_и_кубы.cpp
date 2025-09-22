#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<ll, ll>;
// using lll = __int128_t;

// const ll MAXN = ;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll LIM1 = 1e6 + 1;
const ll LIM2 = 1e9 + 1;

ll f1(ll n) {
    ll l = 0, r = LIM1;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (mid * mid * mid <= n) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

ll f2(ll n) {
    ll l = 0, r = LIM1;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (mid * mid * mid >= n) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}

ll f3(ll n) {
    ll l = 0, r = LIM2;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (mid * mid <= n) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

ll f4(ll n) {
    ll l = 0, r = LIM2;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (mid * mid >= n) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
#ifdef ARCH_Sim0n
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ll a, b, k;
    cin >> a >> b >> k;
    ll s = f2(a), t = f1(b), ans = 0;
    for (ll y = s; y <= t; ++y) {
        ll c = y * y * y, l = max(a, c - k), r = min(b, c + k);
        if (l > r) {
            continue;
        }
        ll _s = f4(l), _t = f3(r);
        if (_s > _t) {
            continue;
        }
        ans += _t - _s + 1;
    }
    cout << ans << '\n';
    return 0;
}