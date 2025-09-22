
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
const ld EPS = 1e-6;

ld f(ld x, ld y, ld a, ld b, ld c) {
    return (a * pow(y - pow(x, 4), 2) + b * pow(1 - x, 2) + c * y);
}

ld t_y(ld x, ld a, ld b, ld c) {
    ld l = -10, r = 10, mid1, mid2;
    while (r - l > EPS) {
        mid1 = l + (r - l) / 3, mid2 = r - (r - l) / 3;
        if (f(x, mid1, a, b, c) <= f(x, mid2, a, b, c)) {
            r = mid2;
        } else {
            l = mid1;
        }
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
#ifdef ARCH_Sim0n
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ll a, b, c;
    cin >> a >> b >> c;
    ld ansx = 1, ansy = 1, mid1, mid2, l = -10, r = 10;
    for (ll i = 0; i < 100; ++i) {
        mid1 = l + (r - l) / 3, mid2 = r - (r - l) / 3;
        ld buf1 = t_y(mid1, a, b, c), buf2 = t_y(mid2, a, b, c);
        if (f(mid1, buf1, a, b, c) <= f(mid2, buf2, a, b, c)) {
            r = mid2, ansx = mid1, ansy = buf1;
        } else {
            l = mid1, ansx = mid2, ansy = buf2;
        }
    }
    cout << fixed << setprecision(4) << ansx << ' ' << ansy << '\n';
    return 0;
}