
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<ll, ll>;
// using lll = __int128_t;

const ll MAXN = 1e18;
const ll MOD = 1e9 + 7;

struct Node {
    ll fl1, fl2, lf, rg, add, zero;
    Node ZERO() {
        return {0, 0, 0, 0, 0, 1};
    }
};

struct SegTree {
    vector<Node> st;
    vector<ll> a;
    void init(vector<ll> &a, ll n) {
        // ! заполнить
        st.assign(4 * n, {0, 0, 0, 0, 0, -1});
        this->a = a;
    }
    void upd(ll v) {
        if (st[2 * v + 1].fl1 && st[2 * v + 2].fl1 && st[2 * v + 2].lf - st[2 * v + 1].rg <= 1) {
            st[v].fl1 = 1;
        } else {
            st[v].fl1 = 0;
        }
        if (st[2 * v + 1].fl2 && st[2 * v + 2].fl2 && st[2 * v + 1].rg - st[2 * v + 2].lf <= 1) {
            st[v].fl2 = 1;
        } else {
            st[v].fl2 = 0;
        }
        st[v].lf = st[2 * v + 1].lf;
        st[v].rg = st[2 * v + 2].rg;
    }
    void build(ll v, ll l, ll r) {
        if (r - l == 1) {
            st[v] = {1, 1, a[l], a[l], 0, -1};
            return;
        }
        ll mid = (l + r) >> 1;
        build(2 * v + 1, l, mid);
        build(2 * v + 2, mid, r);
        upd(v);
    }
    void apply(ll v, ll add) {
        st[v].add += add;
        st[v].lf += add;
        st[v].rg += add;
    }
    void push(ll v, ll l, ll r) {
        ll mid = (l + r) >> 1;
        apply(2 * v + 1, st[v].add);
        apply(2 * v + 2, st[v].add);
        st[v].add = 0;
    }
    void op_add(ll v, ll l, ll r, ll ql, ll qr, ll add) {
        if (ql <= l && r <= qr) {
            apply(v, add);
            return;
        }
        if (qr <= l || r <= ql) {
            return;
        }
        push(v, l, r);
        ll mid = (l + r) >> 1;
        op_add(2 * v + 1, l, mid, ql, qr, add);
        op_add(2 * v + 2, mid, r, ql, qr, add);
        upd(v);
    }
    Node op_path(ll v, ll l, ll r, ll ql, ll qr) {
        if (ql <= l && r <= qr) {
            return st[v];
        }
        if (qr <= l || r <= ql) {
            return st[v].ZERO();
        }
        push(v, l, r);
        Node ansl, ansr;
        ll mid = (l + r) >> 1;
        ansl = op_path(2 * v + 1, l, mid, ql, qr), ansr = op_path(2 * v + 2, mid, r, ql, qr);
        if (ansl.zero == 1) {
            return ansr;
        }
        if (ansr.zero == 1) {
            return ansl;
        }
        bool tot1 = false, tot2 = false;
        if (ansl.fl1 && ansr.fl1 && ansr.lf - ansl.rg <= 1) {
            tot1 = true;
        }
        if (ansl.fl2 && ansr.fl2 && ansl.rg - ansr.lf <= 1) {
            tot2 = true;
        }
        return {tot1, tot2, ansl.lf, ansr.rg, 0, -1};
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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    SegTree sgt;
    sgt.init(a, n);
    sgt.build(0, 0, n);
    for (ll i = 0; i < k; ++i) {
        ll tp;
        cin >> tp;
        if (tp == 1) {
            ll x, y;
            cin >> x >> y;
            bool fl = false;
            if (x > y) {
                fl = true;
                swap(x, y);
            }
            Node ans = sgt.op_path(0, 0, n, x - 1, y);
            if (fl) {
                cout << (ans.fl2 ? "Yes" : "No") << endl;
            } else {
                cout << (ans.fl1 ? "Yes" : "No") << endl;
            }
        } else {
            ll l, r, add;
            cin >> l >> r >> add;
            sgt.op_add(0, 0, n, l - 1, r, add);
        }
    }
    return 0;
}           