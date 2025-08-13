
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
    ll mx, idx;
    bool operator<(const Node &a) const {
        if (mx != a.mx) {
            return mx < a.mx;
        }
        return idx > a.idx;
    }
};

struct SegTree {
    vector<Node> st;
    vector<ll> a;
    void init(ll n, vector<ll> &a) {
        this->a = a;
        st.assign(4 * n, {0, 0});
    }
    void build(ll v, ll l, ll r) {
        if (r - l == 1) {
            st[v] = {a[l], l};
            return;
        }
        ll mid = (l + r) >> 1;
        build(2 * v + 1, l, mid);
        build(2 * v + 2, mid, r);
        st[v] = max(st[2 * v + 1], st[2 * v + 2]);
    }
    void op_set(ll v, ll l, ll r, ll idx, ll val) {
        if (r - l == 1) {
            st[v].mx = val;
            return;
        }
        ll mid = (l + r) >> 1;
        if (idx < mid) {
            op_set(2 * v + 1, l, mid, idx, val);
        } else {
            op_set(2 * v + 2, mid, r, idx, val);
        }
        st[v] = max(st[2 * v + 1], st[2 * v + 2]);
    }
    ll op_get(ll v, ll l, ll r, ll idx, ll val) {
        ll mid = (l + r) >> 1;
        if (l >= idx) {
            if (r - l == 1) {
                if (st[v].mx < val) {
                    return MAXN;
                }
                return st[v].idx + 1;
            }
            if (st[2 * v + 1].mx >= val) {
                return op_get(2 * v + 1, l, mid, idx, val);
            } else {
                return op_get(2 * v + 2, mid, r, idx, val);
            }
        }
        ll ans1 = LLONG_MAX, ans2 = LLONG_MAX;
        if (idx < mid) {
            ans1 = op_get(2 * v + 1, l, mid, idx, val);
        } 
        ans2 =  op_get(2 * v + 2, mid, r, idx, val);
        return min(ans1, ans2);
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
    SegTree sgt;
    sgt.init(n, a);
    sgt.build(0, 0, n);
    while (k--) {
        ll tp;
        cin >> tp;
        if (tp == 0) {
            ll idx, val;
            cin >> idx >> val;
            sgt.op_set(0, 0, n, idx - 1, val);
        } else {
            ll idx, val;
            cin >> idx >> val;
            ll ans = sgt.op_get(0, 0, n, idx - 1, val);
            cout << (ans == MAXN ? -1 : ans) << '\n';
        }
    }
    return 0;
}           