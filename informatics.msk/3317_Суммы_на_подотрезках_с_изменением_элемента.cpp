#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> a, st;

void build(ll v, ll l, ll r) {
    if (r - l == 1) {
        st[v] = a[l];
        return;
    }
    ll mid = ((l + r) >> 1);
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid, r);
    st[v] = st[2 * v + 1] + st[2 * v + 2];
}

ll get(ll v, ll l, ll r, ll ql, ll qr) {
    if (ql <= l && r <= qr) {
        return st[v];
    }
    if (r <= ql || qr <= l) {
        return 0;
    }
    ll mid = ((l + r) >> 1);
    return get(2 * v + 1, l, mid, ql, qr) + get(2 * v + 2, mid, r, ql, qr);
}

void update(ll v, ll l, ll r, ll i, ll x) {
    if (r - l == 1) {
        st[v] = x;
        return;
    }
    ll mid = ((l + r) >> 1);
    if (i < mid) {
        update(2 * v + 1, l, mid, i, x);
    } else {
        update(2 * v + 2, mid, r, i, x);
    }
    st[v] = st[2 * v + 1] + st[2 * v + 2];
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
    st.assign(4 * n, 0);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build(0, 0, n);
    ll q;
    cin >> q;
    for (ll i = 0; i < q; ++i) {
        char op;
        cin >> op;
        if (op == 's') {
            ll l, r;
            cin >> l >> r;
            --l;
            cout << get(0, 0, n, l, r) << ' ';
        }
        if (op == 'u') {
            ll i, x;
            cin >> i >> x;
            --i;
            update(0, 0, n, i, x);
        }
    }
    cout << '\n';
    return 0;
}