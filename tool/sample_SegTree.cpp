#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<ll> a, segTree;

void build(ll v, ll l, ll r) {
    if (r - l == 1) {
        segTree[v] = a[l];
        return;
    }
    ll mid = l + (r - l) / 2;
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid, r);
    segTree[v] = segTree[2 * v + 1] + segTree[2 * v + 2];
}

ll get(ll v, ll l, ll r, ll ql, ll qr) {
    if (qr <= l || r <= ql) {
        return 0;
    }
    if (ql <= l && r <= qr) {
        return segTree[v];
    }
    ll mid = l + (r - l) / 2;
    return get(2 * v + 1, l, mid, ql, qr) + get(2 * v + 2, mid, r, ql, qr);
}

void update(ll v, ll l, ll r, ll i, ll x) {
    if (r - l == 1) {
        segTree[v] = x;
        a[l] = x;
        return; 
    }
    ll mid = l + (r - l) / 2;
    if (i < mid) {
        update(2 * v + 1, l, mid, i, x);
    } else {
        update(2 * v + 2, mid, r, i, x);
    }
    segTree[v] = segTree[2 * v + 1] + segTree[2 * v + 2];
}

int main() {
    ll n, k;
    cin >> n >> k;
    a.resize(n, 0);
    segTree.resize(n * 4);
    for (ll i = 0; i < k; ++i) {
        char c;
        cin >> c;
        if (c == 'A') {
            ll i, x;
            cin >> i >> x;
            --i;
            update(0, 0, n, i, x);
        }
        if (c == 'Q') {
            ll l, r;
            cin >> l >> r;
            --l;
            cout << get(0, 0, n, l, r) << '\n';
        }
    }
    return 0;
}
