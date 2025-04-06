#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<int, int>;

const ll MAXN = 1e18;
const int MOD = 1e9 + 7;

struct node {
    int num, ans;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
#ifdef ARCH_Sim0n
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    int n = s.size();
    vector<node> pref(n + 1, {0, 0}), suf(n + 1, {0, 0});
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i];
        if (s[i] == ')' && pref[i + 1].num) {
            --pref[i + 1].num;
            pref[i + 1].ans += 2;
        } 
        if (s[i] == '(' || s[i] == '?') {
            ++pref[i + 1].num;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        suf[i] =  suf[i + 1];
        if (s[i] == ')' || s[i] == '?') {
            ++suf[i].num;
        }
        if (s[i] == '(' && suf[i].num) {
            --suf[i].num;
            suf[i].ans += 2;
        } 
    }
#ifdef ARCH_Sim0n
    for (auto &[f, s] : pref) {
        cout << f << ' ' << s << " | ";
    }
    cout << '\n';
    for (auto &[f, s] : suf) {
        cout << f << ' ' << s << " | ";
    }
    cout << '\n';
#endif

    int idx = 1;
    for (int i = 1; i <= n; ++i) {
        if (suf[idx].ans + pref[idx].ans + min(suf[idx].num, pref[idx].num) * 2 < suf[i].ans + pref[i].ans + min(suf[i].num, pref[i].num) * 2) {
            idx = i;
        }
    }
    for (ll i = 0; i < ll(s.size()); ++i) {
        if (i < idx && s[i] == '?') {
            s[i] = '(';
        }
        if (i >= idx && s[i] == '?') {
            s[i] = ')';
        }
    }
    cout << s << '\n';
    // cout << idx << '\n';
    return 0;
}          