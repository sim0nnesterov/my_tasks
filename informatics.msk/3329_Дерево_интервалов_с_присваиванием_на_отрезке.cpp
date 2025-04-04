#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Node {
    ll val, set;
};

vector<ll> a;
vector<Node> st;

void apply(ll v, ll l, ll r, ll x) {
    if (x != -1) {
        st[v].val = x;
        st[v].set = x;    
    }
}

void push(ll v, ll l, ll r) {
    ll mid  = (l + r) / 2;
    apply(2 * v + 1, l, mid, st[v].set);
    apply(2 * v + 2, mid, r, st[v].set);
    st[v].set = -1;
}

void build(ll v, ll l, ll r) {
    if (r - l == 1) {
        st[v].val = a[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid, r);
}

void update(ll v, ll l, ll r, ll ql, ll qr, ll x) {
    if (ql <= l && r <= qr) {
        apply(v, l, r, x);
        return;
    }
    if (qr <= l || r <= ql) {
        return;
    }
    push(v, l, r);
    ll mid = (l + r) / 2;
    update(2 * v + 1, l, mid, ql, qr, x);
    update(2 * v + 2, mid, r, ql, qr, x);
}

ll get(ll v, ll l, ll r, ll i) {
    if (r - l == 1) {
        return st[v].val;
    }
    push(v, l, r);
    ll mid = (l + r) / 2;
    if (i < mid) {
        return get(2 * v + 1, l, mid, i);
    } else {
        return get(2 * v + 2, mid, r, i);
    }
}

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
    a.assign(n, 0);
    st.assign(4 * n, {0, -1});
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build(0, 0, n);
    ll q;
    cin >> q;
    for (ll i = 0; i < q; ++i) {
        char op;
        cin >> op;
        if (op == 'g') {
            ll m;
            cin >> m;
            --m;
            cout << get(0, 0, n, m) << ' ';
        }
        if (op == 'a') {
            ll l, r, x;
            cin >> l >> r >> x;
            --l;
            update(0, 0, n, l, r, x);
        }
    }
    cout << '\n';
    return 0;
}