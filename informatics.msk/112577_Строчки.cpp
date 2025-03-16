#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<int, int>;

struct Hash_str {
    const ll M = 1e9 + 33, P = 239;
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
    string a, b;
    cin >> a >> b;
    a += a;
    Hash_str ha, hb;
    ha.init(a);
    hb.init(b);
    ll ans = -1;
    for (ll i = 0; i < b.size(); ++i) {
        if (hb.gethash(1, b.size()) == ha.gethash(b.size() + 1 - i, a.size() - i)) {
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
} 