#include <bits/stdc++.h>

using namespace std;

struct node {
    int m, a;
};

vector<node> t;

void apply(int v, int x) {
    t[v].m += x;
    t[v].a += x;
}

void push(int v) {
    apply(2 * v + 1, t[v].a);
    apply(2 * v + 2, t[v].a);
    t[v].a = 0;
}

void upd(int v, int l, int r, int ql, int qr, int x) {
    if (qr <= l || r <= ql) {
        return;
    }
    if (ql <= l && r <= qr) {
        apply(v, x);
        return;
    }
    push(v);
    int m = (r + l) / 2;
    upd(2 * v + 1, l, m, ql, qr, x);
    upd(2 * v + 2, m, r, ql, qr, x);
    t[v].m = max(t[2 * v + 1].m, t[2 * v + 2].m);
}

int get(int v, int l, int r, int ql, int qr) {
     if (qr <= l || r <= ql) {
        return 0;
    }
    if (ql <= l && r <= qr) {
        return t[v].m;
    }
    push(v);
    int m = (r + l) / 2;
    return max(get(2 * v + 1, l, m, ql, qr), get(2 * v + 2, m, r, ql, qr));
}

int main() {
    // freopen("input.txt", "r", stdin);
    int n, k, m;
    cin >> n >> k >> m;
    t.resize(4 * (n + 1));
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        if (get(0, 0, n + 1, l, r) < k) {
            upd(0, 0, n + 1, l, r, 1);
            cout << "1\n";
        } else {
            cout << "0\n";
        }
   }
}