#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<int, int>;

struct Hash_str {
    const ll M = 1e9 + 9, P = 239;
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
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr); 
#ifdef ARCH_Sim0n
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif  
    int n;
    string s;
    cin >> n >> s;
    Hash_str hs;
    hs.init(s);
    reverse(s.begin(), s.end());
    Hash_str hrs;
    hrs.init(s);
    for (int i = 1; i <= n; ++i) {
        int l = 1, r = i + 1;
        if (hs.gethash(1, 1) != hrs.gethash(n - i + 1, n - i + 1)) {
            cout << "0 ";
            continue;
        }
        while (r - l > 1) {
            int mid = (r + l) / 2;
            if (hs.gethash(1, mid) == hrs.gethash(n - i + 1, n - i + mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << l << ' ';
    }
    cout << '\n';
    return 0;
} 