#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<int, int>;

struct Hash_str {
    const ll M = 1e9 + 9, P = 10;
    vector<ll> pow, hsh;
    void init(string s) {
        s = '_' + s;
        ll n = s.size();
        pow.resize(n);
        hsh.resize(n);
        pow[0] = 1;
        hsh[0] = 0;
        for (ll i = 1; i < n; ++i) {
            pow[i] = (pow[i - 1] * P) % M;
            hsh[i] = ((hsh[i - 1] * P) + (s[i] - 'a' + 1)) % M;
        }
    }
    ll gethash(ll l, ll r) {
        ll hlr = (hsh[r] - hsh[l - 1] * pow[r - l + 1]) % M;
        if (hlr < 0) {
            hlr += M;
        }
        return hlr;
    }
};

int main() {
    string s;
    cin >> s;
    Hash_str hs;
    hs.init(s);
    bool fl = true;
    for (int i = 1; i <= s.size(); ++i) {
        int hsh_medved = hs.gethash(1, i);
        for (int j = 0; j < s.size() / i; ++j) {
            //cout << i * j + 1 << " " << i * (j + 1) << "\n";
            if (hs.gethash(i * j + 1, i * (j + 1)) != hsh_medved) {
                fl = false;
            }
        }
        if (fl) {
            if (s.size() % i != 0) {
                if (hs.gethash(1, s.size() % i) == hs.gethash(s.size() - (s.size() % i) + 1, s.size())) {
                    cout << i << "\n";
                    return 0;
                }
            }
            if (s.size() % i == 0) {
                cout << i << "\n";
                return 0;
            }
        }
        fl = true;
    }

    return 0;
}
