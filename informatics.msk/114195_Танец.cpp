
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
#ifdef ARCH_Sim0n
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ll n, p, k;
    cin >> n >> p >> k;
    ll l = p - 1, r = p + 1;
    if (p % 2 == 1) {
        l += k * 2;
        r += k * 2;
    }
    if (p % 2 == 0) {
        l -= k * 2;
        r -= k * 2;
    }
    l %= n, r %= n;
    if (l == 0) {
        l = n;
    }
    if (r == 0) {
        r = n;
    }
    if (l < 0) {
        l += n;
    }
    if (r < 0) {
        r += n;
    }
    cout << min(l, r) << ' ' << max(l, r) << '\n';
    return 0;
}