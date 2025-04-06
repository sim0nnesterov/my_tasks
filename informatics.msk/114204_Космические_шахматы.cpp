#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<int, int>;

const ll MAXN = 1e18;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
#ifdef ARCH_Sim0n
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    int x_f, y_f;
    cin >> x_f;
    cin >> y_f;
    int x = 0, y = 0;
    while (abs(x_f - x) > 1 || abs(y_f - y) > 1) {
        int x_n, y_n;
        if (abs(x_f - x) >= abs(y_f - y)) {
            x_n = 2 * (x_f - x) / abs(x_f - x);
            y_n = (y_f - y) / abs(y_f - y);
        } else {
            x_n = (x_f - x) / abs(x_f - x);
            y_n = 2 * (y_f - y) / abs(y_f - y);
        }
        x += x_n, y += y_n;
        cout << x << " " << y << "\n";
    }
    while (x < x_f) {
        cout << x + 1 << " " << y + 2 << "\n";
        cout << x - 1 << " " << y + 1 << "\n";
        cout << x + 1 << " " << y << "\n";
        ++x;
    }
    while (x > x_f) {
        cout << x - 1 << " " << y + 2 << "\n";
        cout << x + 1 << " " << y + 1 << "\n";
        cout << x - 1 << " " << y << "\n";
        --x;
    }

    while (y < y_f) {
        cout << x + 2 << " " << y + 1 << "\n";
        cout << x + 1 << " " << y - 1 << "\n";
        cout << x << " " << y + 1 << "\n";
        ++y;
    }

    while (y > y_f) {
        cout << x + 2 << " " << y - 1 << "\n";
        cout << x + 1 << " " << y + 1 << "\n";
        cout << x << " " << y - 1 << "\n";
        --y;
    }

    return 0;
}
