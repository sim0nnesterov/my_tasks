#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct node
{
    ll val, add;
};

vector<node> segTree;

void apply(ll v, ll l, ll r, ll x) {
    segTree[v].val += x * (r - l);
    segTree[v].add += x;
}

void push(ll v, ll l, ll r) {
    ll mid = ((l + r) >> 1);
    apply(2 * v + 1, l, mid, segTree[v].add);
    apply(2 * v + 2, mid, r, segTree[v].add);
    segTree[v].add = 0;
}

void update(ll v, ll l, ll r, ll ql, ll qr, ll x) {
    if (qr <= l || r <= ql) {
        return;
    }
    if (ql <= l && r <= qr) {
        apply(v, l, r, x);
        return;
    }
    push(v, l, r);
    ll mid = (l + r) / 2;
    update(2 * v + 1, l, mid, ql, qr, x);
    update(2 * v + 2, mid, r, ql, qr, x);
    segTree[v].val = segTree[2 * v + 1].val + segTree[2 * v + 2].val;
}

ll get(ll v, ll l, ll r, ll ql, ll qr) {
    if (qr <= l || r <= ql) {
        return 0;
    }
    if (ql <= l && r <= qr) {
        return segTree[v].val;
    }
    push(v, l, r);
    ll mid = (l + r) / 2;
    return get(2 * v + 1, l, mid, ql, qr) + get(2 * v + 2, mid, r, ql, qr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
#ifdef ARCH_Sim0n
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ll n, q;
    cin >> n >> q;
    segTree.resize(4 * n);
    for (ll i = 0; i < q; ++i) {
        string t;
        cin >> t;
        if (t == "1") {
            ll l, r, x;
            cin >> l >> r >> x;
            update(0, 0, n, l, r, x);
        }
        if (t == "2") {
            ll l, r;
            cin >> l >> r;
            cout << get(0, 0, n, l, r) << '\n'; 
        }
    }
    return 0;
}