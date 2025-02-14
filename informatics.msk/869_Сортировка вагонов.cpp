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
    int n, cnt = 1;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    deque<int> dq;
    for (int i = 0; i < n; ++i) {
        dq.push_back(a[i]);
        while (dq.size() && dq.back() == cnt) {
            dq.pop_back();
            ++cnt;
        }
    }
    if (dq.empty()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}           