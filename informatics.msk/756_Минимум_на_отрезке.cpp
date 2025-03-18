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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    deque<pii> dq;
    for (int i = 0; i < n; ++i) {
        while (!dq.empty() && dq.back().first >= v[i]) {
            dq.pop_back();
        }
        dq.push_back({v[i], i});
        if (dq.front().second < i - k + 1) {
            dq.pop_front();
        }
        if (i + 1 >= k) {
            cout << dq.front().first << '\n';
        }
    }
    return 0;
}           
