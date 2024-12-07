#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ld = long double; 
using pii = pair<int, int>;

const int INF = 1e7;
const ld RAM = 1e-9;
const dbl EPS = 1e-7;
const int MOD = 1e7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //? freopen("input.txt", "r", stdin);
    //? freopen("output.txt", "w", stdout); 
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll l = 0, r = 1, ans = 0;
    while (r < n) {
        if (a[r] - a[l] <= k) {
            ++r;
        } else {
            ++l, ans += n - r;
        }
    } 
    cout << ans << '\n';
    return 0;
}
//! OS: ArchLinux ~ notebook