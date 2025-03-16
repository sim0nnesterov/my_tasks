#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Hsh {
    const ll M = 1e6 + 33, P = 10;
    vector<vector<string>> vec;
    Hsh() {
        vec.resize(M);
    }
    ll gethsh(string &s) {
        ll ans = 0, pows = 1;
        for (auto &c : s) {
            // pows = (pows * P) % M;
            ans = (ans * P + (c - 'a' + 1)) % M;
        }
        return ans;
    }
    bool est(ll idx, string &s) {
        for (auto &str : vec[idx]) {
            if (str == s) {
                return true;
            }
        }
        return false;
    }
    void add(string &s) {
        ll hsh_s = gethsh(s);
        if (!est(hsh_s, s)) {
            vec[hsh_s].push_back(s);
        }
    }
    void del(string &s) {
        ll hsh = gethsh(s);
        if (est(hsh, s)) {
            for (int i = 0; i < vec[hsh].size(); ++i) {
                if (vec[hsh][i] == s) {
                    swap(vec[hsh][i], vec[hsh].back());
                    vec[hsh].pop_back();
                }
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
#ifdef ARCH_Sim0n
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    char c = '$';
    Hsh hs;
    string s;
    while (c != '#') {
        cin >> c;
        if (c == '+') {
            cin >> s;
            hs.add(s);
        }
        if (c == '?') {
            cin >> s;
            if (hs.est(hs.gethsh(s), s)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
        if (c == '-') {
            cin >> s;
            hs.del(s);
        }
    }
    return 0;
}