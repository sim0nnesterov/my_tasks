#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<ll, ll>;
// using lll = __int128_t;

const ll MAXN = 1e18;
const int MOD = 1e9 + 7;

struct Node {
    ll val, idx;
    Node *l, *r;
    Node(ll val, ll idx) {
        this->val = val;
        this->idx = idx;
    }
    Node(Node *l, Node *r) {
        this->l = l;
        this->r = r;
        val = l->val + r->val;
    }
};

Node * build(ll l, ll r, vector<ll> &a) {
    if (r - l == 0) {
        return new Node(a[l], l);
    }
    ll mid = (l + r) >> 1;
    return new Node(build(l, mid, a), build(mid + 1, r, a));
}

void upd(Node *n, ll l, ll r, ll idx, ll op) {
    if (r - l == 0) {
        n->val = 1;
        n->idx = op;
        return;
    }
    ll mid = (l + r) >> 1;
    n->l = new Node(*(n->l));
    n->r = new Node(*(n->r));
    if (idx <= mid) {
        upd(n->l, l, mid, idx, op);
    } else {
        upd(n->r, mid + 1, r, idx, op);
    }
    n->val = n->l->val + n->r->val;
    return;
} 

ll getk(Node *nl, Node *nr, ll l, ll r, ll k) {
    if (nr->val - nl->val < k) {
        return -1;
    }
    if (r - l == 0) {
        return nr->idx;
    }
    ll mid = (l + r) >> 1;
    if (nr->l->val - nl->l->val < k) {
        return getk(nl->r, nr->r, mid + 1, r, k - (nr->l->val - nl->l->val));
    } else {
        return getk(nl->l, nr->l, l, mid, k);
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
    vector<ll> a(n), v(n), buf, sml(n, 0);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        buf.push_back(a[i]);
    }
    sort(buf.begin(), buf.end());
    buf.erase(unique(buf.begin(), buf.end()), buf.end());
    for (ll i = 0; i < n; ++i) {
        v[i] = lower_bound(buf.begin(), buf.end(), a[i]) - buf.begin();
    }
    vector<Node*> st;
    st.push_back(build(0, n - 1, sml));
    for (ll i = 1; i <= n; ++i) {
        st.push_back(new Node(*st[i - 1]));
        upd(st[i], 0, n - 1, v[i - 1], i);
    }
    ll m;
    cin >> m;
    for (ll i = 0; i < m; ++i) {
        ll l, r, k;
        cin >> l >> r >> k;
        cout << getk(st[l - 1], st[r], 0, n - 1, k) - l + 1 << '\n';
    }
    return 0;
}   