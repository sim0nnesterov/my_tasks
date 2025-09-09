#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ld = long double; 
using pii = pair<int, int>;

const ll INF = 2 * 1e18;
const ld RAM = 1e-9;
const dbl EPS = 1e-7;
const int MOD = 1e7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //? freopen("input.txt", "r", stdin);
    //? freopen("output.txt", "w", stdout); 
    ll n, k, p;
    cin >> n;
    vector<ll> a(n), t(n), q(n);
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> a[i] >> x >> t[i];
        t[i] += x;
    }
    cin >> k >> p;
    ll l = 0, r = INF;
    while (l < r) {
        ll mid = (l + r) / 2, sum = 0;
        for (ll i = 0; i < n; ++i) {
            if (mid < t[i]) {
                q[i] = 0;
            } else if (a[i] == 0) {
                q[i] = p;
            } else {
                q[i] = min(p, (mid - t[i]) / a[i]);
            }   
        }
        sort(q.rbegin(), q.rend());
        for (ll i = 0; i < min(n, k); ++i) {
            sum += q[i];
        }
        if (sum < p) {
            l = mid + 1;
        } else {
            r = mid;
        }
    } 
    cout << l << '\n';
    return 0;
}
