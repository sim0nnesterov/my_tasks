#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
#ifdef ARCH_Sim0n
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif  
    ll x1, x2, x3, x, y1, y2, y3, y;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x >> y;
    ll s1 = (x2 - x1) * (y - y1) - (x - x1) * (y2 - y1),
    s2 = (x3 - x2) * (y - y2) - (x - x2) * (y3 - y2),
    s3 = (x1 - x3) * (y - y3) - (x - x3) * (y1 - y3),
    tot = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    if (abs(tot) == abs(s1) + abs(s2) + abs(s3)) {
        cout << "In\n";
    } else {
        cout << "Out\n";
    }
    return 0;
}