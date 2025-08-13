#include <bits/stdc++.h>

using namespace std;

struct node {
    int sz, op, cl; 
};

vector<node> t;

node merge(node v1, node v2) {
    int sz = v1.sz + v2.sz + min(v1.op, v2.cl),
    op = v1.op + v2.op - min(v1.op, v2.cl),
    cl = v1.cl + v2.cl - min(v1.op, v2.cl);
    return {sz, op, cl};
}

void build(int v, int l, int r, const string &s) {
    if (r - l == 1) {
        if (s[l] == '(') {
            t[v].op = 1;
        } else {
            t[v].cl = 1;
        }
        return;
    }
    int mid = l + (r - l) / 2;
    build(2 * v + 1, l, mid, s);
    build(2 * v + 2, mid, r, s);
    t[v] = merge(t[2 * v + 1], t[2 * v + 2]);
}

node get(int v, int l, int r, int ql, int qr) {
    if (qr <= l || r <= ql) {
        return {0, 0, 0};
    }
    if (ql <= l && r <= qr) {
        return t[v];
    }
    int mid = l + (r - l) / 2;
    return merge(get(2 * v + 1, l, mid, ql, qr), get(2 * v + 2, mid, r, ql, qr));
}

int main() {
    // freopen("input.txt", "r", stdin);
    string s;
    int m;
    cin >> s >> m;
    t.resize(4 * s.size());
    build(0, 0, s.size(), s);
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        --l;
        node ans = get(0, 0, s.size(), l, r);
        cout << ans.sz * 2 << '\n';
    }
    return 0;
}