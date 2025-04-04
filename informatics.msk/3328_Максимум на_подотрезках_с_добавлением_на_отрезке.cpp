#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<ll, ll>;

struct node {
    ll val, add;
};

vector<ll> a;
vector<node> segTree;

void apply(ll v, ll add) {
    segTree[v].val += add;
    segTree[v].add += add;
} 

void push(ll v) {
    apply(2 * v + 1, segTree[v].add);
    apply(2 * v + 2, segTree[v].add);
    segTree[v].add = 0;
}

void build(ll v, ll l, ll r) {
    if (r - l == 1) {
        segTree[v].val = a[l];
        return;
    }
    ll mid = ((l + r) >> 1);
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid, r);
    segTree[v].val = max(segTree[2 * v + 1].val, segTree[2 * v + 2].val);
}

ll get(ll v, ll l, ll r, ll ql, ll qr) {
    if (ql <= l && r <= qr) {
        return segTree[v].val;
    }
    if (qr <= l || r <= ql) {
        return 0;
    }
    push(v);
    ll mid = ((l + r) >> 1);
    return max(get(2 * v + 1, l, mid, ql, qr), get(2 * v + 2, mid, r, ql, qr));
}

void update(ll v, ll l, ll r, ll ql, ll qr, ll x) {
    if (qr <= l || r <= ql) {
        return;
    }
    if (ql <= l && r <= qr) {
        apply(v, x);
        return;
    }
    push(v);
    ll mid = ((l + r) >> 1);
    update(2 * v + 1, l, mid, ql, qr, x);
    update(2 * v + 2, mid, r, ql, qr, x);
    segTree[v].val = max(segTree[2 * v + 1].val, segTree[2 * v + 2].val);  
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
    segTree.assign(4 * n, {0, 0});
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build(0, 0, n);
    ll q;
    cin >> q;
    for (ll i = 0; i < q; ++i) {
        char op;
        cin >> op;
        if (op == 'm') {
            ll l, r;
            cin >> l >> r;
            --l;
            cout << get(0, 0, n, l, r) << ' ';
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