#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<int, int>;

struct Hash_str {
    const ll M = 1e9 + 33, P = 10;
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr); 
#ifdef ARCH_Sim0n
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif  
    string s;
    cin >> s;
    ll n = s.size();
    vector<int> us;
    for (ll i = 1; i <= n; ++i) {
        if (n % i == 0) {
            us.push_back(i);
        }
    }
    Hash_str hs;
    hs.init(s);
    ll ans = 1;
    for (auto &el : us) {
        ll hsh_s = hs.gethash(1, el);
        bool fl = true;
        for (ll k = 0; k < s.size() / el; ++k) {
            if (hs.gethash(el * k + 1, el * (k + 1)) != hsh_s) {
                fl = false;                
            }
        }
        if (fl) {
            cout << s.size() / el << "\n";
            return 0;
        }
    }
    return 0;
} 