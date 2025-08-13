#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct SegTree {
    vector<ll> st;
    void init(ll n) {
        st.assign(4 * n, 0);
    }
    void build(ll v, ll l, ll r, vector<ll> &a) {
        if (r - l == 1) {
            st[v] = (a[l] == 0) ? 1 : 0;
            return;
        }
        ll mid = (l + r) >> 1;
        build(2 * v + 1, l, mid, a);
        build(2 * v + 2, mid, r, a);
        st[v] = st[2 * v + 1] + st[2 * v + 2];
    }
    void update(ll v, ll l, ll r, ll idx, ll val) {
        if (r - l == 1) {
            st[v] = (val == 0) ? 1 : 0;
            return;
        }
        ll mid = (l + r) >> 1;
        if (idx < mid) {
            update(2 * v + 1, l, mid, idx, val);
        } else {
            update(2 * v + 2, mid, r, idx, val);
        }
        st[v] = st[2 * v + 1] + st[2 * v + 2];
    }
    ll getk(ll v, ll l, ll r, ll ql, ll qr, ll& k) {
        if (qr <= l || r <= ql) return -1;
        if (ql <= l && r <= qr) {
            if (st[v] < k) {
                k -= st[v];
                return -1;
            }
            if (r - l == 1) {
                return l;
            }
        }
        ll mid = (l + r) >> 1;
        ll left_res = getk(2 * v + 1, l, mid, ql, qr, k);
        if (left_res != -1) return left_res;
        return getk(2 * v + 2, mid, r, ql, qr, k);
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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    SegTree sgt;
    sgt.init(n);
    sgt.build(0, 0, n, a);
    ll q;
    cin >> q;
    while (q--) {
        char tp;
        cin >> tp;
        if (tp == 'u') {
            ll idx, val;
            cin >> idx >> val;
            sgt.update(0, 0, n, idx - 1, val);
        } else {
            ll l, r, k;
            cin >> l >> r >> k;
            ll res = sgt.getk(0, 0, n, l - 1, r, k);
            cout << (res == -1 ? -1 : res + 1) << '\n';
        }
    }
    return 0;
}