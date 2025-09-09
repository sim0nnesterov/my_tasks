#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const ll INF = 1e9;
const ld RAM = 1e-9;
const int MOD = 1e9 + 7;

bool f(ull a, ull k, ull b, ull m, ull x, ull mid) {
    return (a * (mid - (mid / k)) + b * (mid - (mid / m))) < x;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);  
    //? freopen("input.txt", "r", stdin);
    //? freopen("output.txt", "w", stdout);
    ull a, k, b, m, x;
    cin >> a >> k >> b >> m >> x;
    ull l = -1, r = 1.0 * x / (a * ((k - 1) / (1.0 * k)) + b * ((m - 1) / (1.0 * m))) + k;
    while (r -l > 1) {
        ull mid = (l + r) / 2;
        if (f(a, k, b, m, x, mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << r << '\n';
    return 0;

}           
//! OS: ArchLinux ~ notebook  