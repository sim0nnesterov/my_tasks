#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<ll, ll>;
// using lll = __int128_t;

const ll MAXN = 1e18;
const int MOD = 1e9 + 7;

struct Node {
    ll pref, suff, ans;
    bool fl;
};

struct SegTree {
    vector<Node> st;
    vector<ll> a;
    void init(ll n, const vector<ll> &a) {
        st.assign(4 * n, {0, 0, 0, false});
        this->a = a;
    }
    void build(ll v, ll l, ll r) {
        if (r - l == 1) {
            st[v].pref = (a[l] == 0 ? 1 : 0);
            st[v].suff = (a[l] == 0 ? 1 : 0);
            st[v].ans = (a[l] == 0 ? 1 : 0);
            st[v].fl = (a[l] == 0 ? 1 : 0);
            return;
        }
        ll mid = (l + r) >> 1;
        build(2 * v + 1, l, mid);
        build(2 * v + 2, mid, r);
        st[v].ans = max({st[2 * v + 1].ans, st[2 * v + 2].ans, st[2 * v + 1].suff + st[2 * v + 2].pref});
        st[v].pref = st[2 * v + 1].pref + (st[2 * v + 1].fl ? st[2 * v + 2].pref : 0);
        st[v].suff = st[2 * v + 2].suff + (st[2 * v + 2].fl ? st[2 * v + 1].suff : 0); 
        st[v].fl = (st[2 * v + 1].fl && st[2 * v + 2].fl);
    }
    void update(ll v, ll l, ll r, ll idx, ll val) {
        if (r - l == 1) {
            st[v].pref = (val == 0 ? 1 : 0);
            st[v].suff = (val == 0 ? 1 : 0);
            st[v].ans = (val == 0 ? 1 : 0);
            st[v].fl = (val == 0 ? 1 : 0);
            return;
        }
        ll mid = (l + r) >> 1;
        if (idx < mid) {
            update(2 * v + 1, l, mid, idx, val);
        } else {
            update(2 * v + 2, mid, r, idx, val);
        }
        st[v].ans = max({st[2 * v + 1].ans, st[2 * v + 2].ans, st[2 * v + 1].suff + st[2 * v + 2].pref});
        st[v].pref = st[2 * v + 1].pref + (st[2 * v + 1].fl ? st[2 * v + 2].pref : 0);
        st[v].suff = st[2 * v + 2].suff + (st[2 * v + 2].fl ? st[2 * v + 1].suff : 0); 
        st[v].fl = (st[2 * v + 1].fl && st[2 * v + 2].fl);
    }
    Node get_ans(ll v, ll l, ll r, ll ql, ll qr) {
        if (ql <= l && r <= qr) {
            return st[v];
        }
        if (qr <= l || r <= ql) {
            return {0, 0, 0};
        }
        ll mid = (l + r) >> 1;
        Node a = get_ans(2 * v + 1, l, mid, ql, qr), 
        b = get_ans(2 * v + 2, mid, r, ql, qr);
        return {a.pref + (a.fl ? b.pref : 0), b.suff + (b.fl ? a.suff : 0), max({a.ans, b.ans, a.suff + b.pref}), (a.fl && b.fl)};
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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    SegTree sgt;
    sgt.init(n, a);
    sgt.build(0, 0, n);
    ll q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;
        if (t == "QUERY") {
            ll l, r;
            cin >> l >> r;
            cout << sgt.get_ans(0, 0, n, l - 1, r).ans << '\n';
        } else {
            ll idx, val;
            cin >> idx >> val;
            sgt.update(0, 0, n, idx - 1, val);
        }
    }
    return 0;
}