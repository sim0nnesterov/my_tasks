#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct FenTree {
    vector<ll> tr;
    ll sz;
    void build(ll n) {
        tr.assign(n + 1, 0);
        sz = n;
    }
    void add(ll idx, ll num) {
        for (; idx <= sz; idx += idx & -idx) {
            tr[idx] += num;
        }
    }
    ll sum(ll l, ll r) {
        return get_sum(r - 1) - get_sum(l - 1);
    }
    ll get_sum(ll idx) {
        ll res = 0;
        for (; idx > 0; idx -= idx & -idx) {
            res += tr[idx];
        }
        return res;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifdef ARCH_SIM0N
    freopen("input.txt", "r", stdin);
#endif
    ll n;
    cin >> n;
    FenTree ft;
    ft.build(n);
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        ft.add(i + 1, x);
    }
    // for (auto &el : ft.tr) {
    //     cout << el << ' ';
    // }
    ll q;
    cin >> q;
    for (ll i = 0; i < q; ++i) {
        ll l, r;
        cin >> l >> r;
        cout << ft.sum(l, r + 1) << ' ';
    }
    cout << '\n';
    return 0;
}