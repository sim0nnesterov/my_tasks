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
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    ll ya = 0, t = n, p = n;
    for (ll i = 1; i <= n; i++) {
        if (t < i) {
            p = i;
            break;
        }
        t -= i;
    }
    ll o = (p * (p + 1)) / 2;
    for (ll i = 1; i <= p; i++) {
        if (o == n + i) {
            continue;
        }
        ya += (i * (i - 1)) / 2;
    }
    cout << ya;
    return 0;
}
