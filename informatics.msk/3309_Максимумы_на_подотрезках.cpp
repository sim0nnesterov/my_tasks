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
    segTree[v] = max(segTree[2 * v + 1], segTree[2 * v + 2]);
}

ll get(ll v, ll l, ll r, ll ql, ll qr) {
    if (qr <= l || r <= ql) {
        return 0;
    }
    if (ql <= l && r <= qr) {
        return segTree[v];
    }
    ll mid = l + (r - l) / 2;
    return max(get(2 * v + 1, l, mid, ql, qr), get(2 * v + 2, mid, r, ql, qr));
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
    ll n;
    cin >> n;
    a.reserve(n);
    segTree.resize(4 * n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build(0, 0, n);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l;
        cout << get(0, 0, n, l, r) << '\n';
    }
    return 0;
}