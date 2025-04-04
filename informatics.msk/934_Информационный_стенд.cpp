#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Node {
    ll val;
    Node *left = nullptr, *right = nullptr;
};

void update(Node* i, ll val, ll l, ll r, ll w) {
    if (r - l == 1) {
        i->val -= val;
        cout << r << '\n';
        return;
    }
    ll mid = (l + r) / 2;
    if (i->left == nullptr) {
        i->left = new Node{w};
    }
    if (i->right == nullptr) {
        i->right = new Node{w};
    }
    if (i->left->val >= val) {
        update(i->left, val, l, mid, w);
    } else {
        update(i->right, val, mid, r, w);
    }
    i->val = max(i->left->val, i->right->val);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifdef ARCH_Sim0n
    freopen("input", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ll h, w, n;
    cin >> h >> w >> n; 
    Node* root = new Node{w};
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        if (root->val < x) {
            cout << "-1\n";
        } else {
            update(root, x, 0, h, w);
        }
    }
    return 0;
}