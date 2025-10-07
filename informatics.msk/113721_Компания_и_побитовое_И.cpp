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
    freopen("E.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<ll> a(n), cnt(32, 0);
    ll sum = 0;
    for (auto& i : a) {
        cin >> i;
        for (int j = 0; j < 32; j++) {
            if (i & (1 << j)) cnt[j]++;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 32; j++) {
            if (a[i] & (1 << j)) {
                ans += (cnt[j] - 1) * (1 << j);
            }
        }
    }
    cout << ans / 2;
    return 0;
}
