
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned ll;
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
    // freopen("output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    ll a = n * (n + 1) * (n + 2) / 6, b = 0;
    for (ll i = 1; i <= n; ++i) {
        ll c = n - 2 * i + 1;
        if (c <= 0) {
            break;
        }
        ll d = n - 2 * i + 2;
        b += c * d / 2;
    }
    cout << a + b << '\n';
    return 0;
}