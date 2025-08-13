#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<int, int>;

struct Node {
    ll val, add;
};

struct SegTree {
    vector<Node> st;
    void init(ll n) {
        st.assign(4 * n, {0, 0});
    }
    ll get(ll v, ll l, ll r, ll ql, ll qr) {
        if (ql <= l && r <= qr) {
            return st[v].val;
        }
        if (qr <= l || r <= ql) {
            return 0;
        }
        push(v);
        ll mid = (l + r) >> 1;
        return max(get(2 * v + 1, l, mid, ql, qr), get(2 * v + 2, mid, r, ql, qr));
    }
    void apply(ll v, ll val) {
        st[v].val += val;
        st[v].add += val;
    }
    void push(ll v) {
        apply(2 * v + 1, st[v].add);
        apply(2 * v + 2, st[v].add);
        st[v].add = 0;
    }
    void add(ll v, ll l, ll r, ll ql, ll qr, ll val) {
        if (ql <= l && r <= qr) {
            apply(v, val);
            return;
        }
        if (qr <= l || r <= ql) {
            return;
        }
        push(v);
        ll mid = (l + r) >> 1;
        add(2 * v + 1, l, mid, ql, qr, val);
        add(2 * v + 2, mid, r, ql, qr, val);
        st[v].val = max(st[v * 2 + 1].val, st[2 * v + 2].val);
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
    ll n, k, m;
    cin >> n >> k >> m;
    SegTree sgt;
    sgt.init(n);
    for (ll i = 0; i < m; ++i) {
        ll l, r;
        cin >> l >> r;
        ll res = sgt.get(0, 0, n, l, r);
        if (res < k) {
            cout << "1\n";
            sgt.add(0, 0, n, l, r, 1);
        } else {
            cout << "0\n";
        }

    }
    return 0;
}