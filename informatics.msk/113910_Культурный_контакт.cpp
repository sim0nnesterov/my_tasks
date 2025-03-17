#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Hashstr{
    const ll M = 1e9 + 9;
    vector<ll> hash_s, hsh;
    void init(string s) {
        s = '_' + s;
        hash_s.assign(26, 0);
        hsh.assign(s.size(), 0);
        mt19937 rng(random_device{}());
        uniform_int_distribution<int> dist(1, M);
        for (ll i = 0; i < 26; ++i) {
            hash_s[i] = dist(rng);
        }
        for (ll i = 1; i < s.size(); ++i) {
            hsh[i] = (hsh[i - 1] + hash_s[s[i] - 'a']);
        }
    }
    ll gethash(ll l, ll r) {
        ll hlr = hsh[r] - hsh[l - 1];
        return hlr;
    }
};


int main() {
    string s;
    cin >> s;
    Hashstr hs;
    hs.init(s);
    ll ans = 0, mnhsh = 0;
    vector<ll> p;
    for (ll i = 1; i <= s.size(); ++i) {
        if (s.size() % i == 0) {
            p.push_back(i);
        }
    }
    for (auto &el : p) {
        mnhsh = hs.gethash(1, el);
        bool fl = true;
        for (ll k = 0; k < s.size() / el; ++k) {
            if (hs.gethash(k * el + 1, (k + 1) * el) != mnhsh) {
                fl = false;
            }
        }
        if (fl == true) {
            cout << s.size() / el << '\n';
            return 0;
        }
    }
    return 0;
}