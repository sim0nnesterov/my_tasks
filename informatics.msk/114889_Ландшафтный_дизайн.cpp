
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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> buf1(n), buf2(n);
    for (ll i = 0; i < n; ++i) {
        buf1[i] = a[i] + (i % 2 == 1 ? k : 0);
        buf2[i] = a[i] - (i % 2 == 1 ? k : 0);
    }
    sort(buf1.begin(), buf1.end());
    sort(buf2.begin(), buf2.end());
    ll ans11 = buf1[n / 2], ans12 = buf1[(n - 1) / 2], ans21 = buf2[n / 2], ans22 = buf2[(n - 1) / 2];
    ll cnt11 = 0, cnt12 = 0, cnt21 = 0, cnt22 = 0;
    for (auto &el : buf1) {
        cnt11 += abs(el - ans11);
        cnt12 += abs(el - ans12);
    }
    for (auto &el : buf2) {
        cnt21 += abs(el - ans21);
        cnt22 += abs(el - ans22);
    }
    cout << min({cnt11, cnt12, cnt21, cnt22}) << '\n';
    return 0;
}