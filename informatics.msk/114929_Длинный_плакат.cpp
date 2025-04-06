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
    string s, ans = "";
    cin >> s;
    deque<int> dq;
    int k;
    cin >> k;
    for (int i = 0; i < s.size(); ++i) {
        while (dq.size() && s[dq.back()] < s[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i + 1 > k) {
            ans += s[dq.front()];
            dq.pop_front();
        }
    }
    cout << ans << '\n';
    return 0;
}           