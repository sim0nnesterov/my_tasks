
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<ll, ll>;
// using lll = __int128_t;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
#ifdef ARCH_Sim0n
    freopen("input.txt", "r", stdin);
    // freopen("ans.txt", "w", stdout);
#endif
    ld v, d, n;
    cin >> v >> d >> n;
    vector<pair<ld, ld>> a(n);
    for (ll i = 0; i < n; ++i) {
        ld p, h, m;
        char c;
        cin >> p >> h >> c >> m;
        a[i] = {p, h * 60 + m};
    }
    if (!n) {
        cout << "00:00\n";
        return 0;
    }
    ld l = 0, r = a.back().second, mid, tm, p;
    for (ll it = 0; it < 100; ++it) {
        mid = (l + r) / 2, tm = mid, p = 0;
        for (ll i = 0; i < n - 1; ++i) {
            tm += (a[i].first - p) / v;
            if (tm >= a[i].second) {
                tm += d;
            }
            p = a[i].first;
        }
        tm += (a.back().first - p) / v;
        if (tm < a.back().second) {
            l = mid;
        } else {
            r = mid;
        }
    }
    tm = r, p = 0;
    ll cnt = 0;
    for (ll i = 0; i < n - 1; ++i) {
        tm += (a[i].first - p) / v;
        if (tm >= a[i].second) {
            ++cnt;
            tm += d;
        }
        p = a[i].first;
    }
    tm += (a.back().first - p) / v;
    ll ans = ceil(tm + d * (n - cnt) + a.back().first / v);
    printf("%02d:%02d\n", ans / 60, ans % 60);
    return 0;
}