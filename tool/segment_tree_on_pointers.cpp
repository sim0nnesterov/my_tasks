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
    ll val;
    Node *l, *r;
    Node(ll val) {
        this->val = val;
    }
    Node(Node *l, Node *r) {
        this->l = l;
        this->r = r;
        val = l->val + r->val;
    }
};

Node * build(ll l, ll r, vector<ll> &a) {
    if (r - l == 1) {
        return new Node(a[l]);
    }
    ll mid = (l + r) >> 1;
    return new Node(build(l, mid, a), build(mid, r, a));
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
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    Node *root = build(0, n, a);
    
    return 0;
}           
