
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
    ll val, g, add;
};

struct AnimeSegTree {
    vector<Node> st;
    vector<ll> a;
    void init(vector<ll> &a, ll n) {
        st.assign(4 * n, {0, 0, 0});
        this->a = a;
    }
    void build(ll v, ll l, ll r) {
        if (r - l == 1) {
            st[v] = {a[l], 0, 0};
            return;
        }
        ll mid = (l + r) >> 1;
        build(2 * v + 1, l, mid);
        build(2 * v + 2, mid, r);
        ll g = gcd(gcd(st[2 * v + 1].g, st[2 * v + 2].g), st[2 * v + 1].val - st[2 * v + 2].val);
        st[v] = {st[2 * v + 1].val, g, 0};
    }
    void apply(ll v, ll add) {
        st[v].add += add;
        st[v].val += add;
    }
    void push(ll v) {
        apply(2 * v + 1, st[v].add);
        apply(2 * v + 2, st[v].add);
        st[v].add = 0;
    }
    void op_add(ll v, ll l, ll r, ll ql, ll qr, ll val) {
        if (ql <= l && r <= qr) {
            apply(v, val);
            return;
        }
        if (qr <= l || r <= ql) {
            return;
        }
        push(v);
        ll mid = (l + r) >> 1;
        op_add(2 * v + 1, l, mid, ql, qr, val);
        op_add(2 * v + 2, mid, r, ql, qr, val);
        ll g = gcd(gcd(st[2 * v + 1].g, st[2 * v + 2].g), st[2 * v + 1].val - st[2 * v + 2].val);
        st[v] = {st[2 * v + 1].val, g, 0};
    }
    ll op_get_gcd(ll v, ll l, ll r, ll ql, ll qr) {
        if (ql <= l && r <= qr) {
            return gcd(st[v].val, st[v].g);
        }
        if (qr <= l || r <= ql) {
            return 0;
        }
        push(v);
        ll mid = (l + r) >> 1;
        return gcd(op_get_gcd(2 * v + 1, l, mid, ql, qr), op_get_gcd(2 * v + 2, mid, r, ql, qr));
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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    AnimeSegTree asgt;
    asgt.init(a, n);
    asgt.build(0, 0, n);
    while (k--) {
        ll tp;
        cin >> tp;
        if (tp == 1) {
            ll l, r, val;
            cin >> l >> r >> val;
            asgt.op_add(0, 0, n, l - 1, r, val);
        } else {
            ll l, r;
            cin >> l >> r;
            cout << asgt.op_get_gcd(0, 0, n, l - 1, r) << '\n';
        }
    }
    return 0;
}          