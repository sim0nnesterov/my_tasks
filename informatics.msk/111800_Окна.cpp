#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

const ll MAXN = 1e6;

struct Event {
    ll x, y1, y2, tp;
};

struct Node {
    ll val, add, idx;
};

vector<Node> st;

bool cmp(const Event &a, const Event &b) {
    if (a.x != b.x) {
        return a.x < b.x;
    } 
    if (a.tp != b.tp) {
        return a.tp > b.tp;
    }
    if (a.y1 != b.y1) {
        return a.y1 < b.y1;
    }
    return a.y2 < b.y2;
}

void apply(ll v, ll l, ll r, ll x) {
    st[v].val += x;
    st[v].add += x; 
}

void push(ll v, ll l, ll r) {
    ll mid = (l + r) / 2;
    apply(2 * v + 1, l, mid, st[v].add);
    apply(2 * v + 2, mid, r, st[v].add);
    st[v].add = 0;
}

Node gtNode(const Node &a, const Node &b) {
    Node ans = {0, 0, 0};
    ans.val = max(a.val, b.val);
    ans.idx = (max(a.val, b.val) == a.val ? a.idx : b.idx);
    return ans;
}

void build(ll v, ll l, ll r) {
    if (r - l == 1) {
        st[v].idx = l;
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid, r);
    st[v] = gtNode(st[2 * v + 1], st[2 * v + 2]);
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
    st[v] = gtNode(st[2 * v + 1], st[2 * v + 2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
#ifdef ARCH_Sim0n
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ll n, sz = 0;
    cin >> n;
    vector<Event> a;
    for (ll i = 0; i < n; ++i) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a.push_back({x1, y1 + MAXN, y2 + MAXN, 1});
        a.push_back({x2, y1 + MAXN, y2 + MAXN, -1});
        sz = max(sz, y2 + MAXN);
    }
    st.assign((sz + 1) * 4, {0, 0, 0});
    sort(a.begin(), a.end(), cmp);
    build(0, 0, sz + 1);
    ll ans = 0;
    pii crd;
    for (ll i = 0; i < 2 * n; ++i) {
        update(0, 0, sz + 1, a[i].y1, a[i].y2 + 1, a[i].tp);
        if (st[0].val > ans) {
            ans = st[0].val;
            crd.first = a[i].x;
            crd.second = st[0].idx;
        }
    }
    cout << ans << '\n' << crd.first << ' ' << crd.second - MAXN << '\n';
    return 0;
}