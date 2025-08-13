#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<ll, ll>;

const ll MAXN = 1e18;
const int MOD = 1e9 + 7;

struct Node {
    ll len, cnt;
};

struct SegTree {
    vector<Node> st;
    void init(ll n) {
        st.assign(4 * n, {0, 0});
    }
    Node mxNode(Node a, Node b) {
        if (a.len > b.len) {
            return a;
        }
        if (a.len < b.len) {
            return b;
        }
        return {a.len, (a.cnt + b.cnt) % MOD};
    }
    Node get(ll v, ll l, ll r, ll ql, ll qr) {
        if (ql <= l && r <= qr) {
            return st[v];
        }
        if (qr <= l || r <= ql) {
            return {0, 0};
        }
        ll mid = (l + r) / 2;
        return mxNode(get(2 * v + 1, l, mid, ql, qr), get(2 * v + 2, mid, r, ql, qr));
    }
    void update(ll v, ll l, ll r, ll idx, Node val) {
        if (r - l == 1) {
            if (val.len > st[v].len) {
                st[v] = val;
            } else if (val.len == st[v].len) {
                st[v].cnt = (st[v].cnt + val.cnt) % MOD;
            }
            return;
        }
        ll mid = (l + r) >> 1;
        if (idx < mid) {
            update(2 * v + 1, l, mid, idx, val);
        } else {
            update(2 * v + 2, mid, r, idx, val);
        }
        st[v] = mxNode(st[2 * v + 1], st[2 * v + 2]);
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
    ll n;
    cin >> n;
    vector<ll> a(n), v(n), buf;
    set<ll> s;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        buf.push_back(a[i]);
    }
    
    sort(buf.begin(), buf.end());
    buf.erase(unique(buf.begin(), buf.end()), buf.end());
    for (ll i = 0; i < n; ++i) {
        v[i] = lower_bound(buf.begin(), buf.end(), a[i]) - buf.begin();
    }

    SegTree sgt;
    sgt.init(buf.size());

    for (ll i = 0; i < n; ++i) {
        Node current;
        if (v[i] == 0) {
            current = {1, 1};
        } else {
            Node mx = sgt.get(0, 0, buf.size(), 0, v[i]);
            if (mx.len == 0) {
                current = {1, 1};
            } else {
                current = {mx.len + 1, mx.cnt};
            }
        }
        sgt.update(0, 0, buf.size(), v[i], current);
    }

    cout << sgt.st[0].cnt << '\n';
    
    return 0;
}