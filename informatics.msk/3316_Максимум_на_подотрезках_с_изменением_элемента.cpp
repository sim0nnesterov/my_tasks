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
    st[v] = max(st[2 * v + 1], st[2 * v + 2]);
}

ll get(ll v, ll l, ll r, ll ql, ll qr) {
    if (ql <= l && r <= qr) {
        return st[v];
    }
    if (qr <= l || r <= ql) {
        return 0;
    }
    ll mid = ((l + r) >> 1);
    return max(get(2 * v + 1, l, mid, ql, qr), get(2 * v + 2, mid, r, ql, qr));
}

void update(ll v, ll l, ll r, ll i, ll x) {
    if (r - l == 1) {
        st[v] = x;
        return;
    }
    ll mid = ((l + r) >> 1);
    if (mid > i) {
        update(2 * v + 1, l, mid, i, x);
    } else {
        update(2 * v + 2, mid, r, i, x);
    }
    st[v] = max(st[2 * v + 1], st[2 * v + 2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, q;
    cin >> n;
    a.assign(n, 0);
    st.assign(4 * n, 0);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build(0, 0, n);
    cin >> q;
    for (int j = 0; j < q; ++j) {
        char c;
        cin >> c;
        if (c == 's') {
            int l, r;
            cin >> l >> r;
            --l;
            cout << get(0, 0, n, l, r) << ' ';
        } 
        if (c == 'u') {
            int i, x;
            cin >> i >> x;
            --i;
            update(0, 0, n, i, x);
        }
    }
    cout << '\n';
    return 0;
}