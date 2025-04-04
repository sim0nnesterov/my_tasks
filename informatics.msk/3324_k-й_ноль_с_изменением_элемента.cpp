#include <bits/stdc++.h>

using namespace std;

vector<int> a, st;

void build(int v, int l, int r) {
    if (r - l == 1) {
        st[v] = (a[l] == 0 ? 1 : 0);
        return;
    } 
    int mid = ((l + r) >> 1);
    build(2 * v + 1, l, mid);
    build(2 * v + 2, mid, r);
    st[v] = st[2 * v + 1] + st[2 * v + 2];
}

void update(int v, int l, int r, int i, int x) {
    if (r - l == 1) {
        st[v] = (x == 0 ? 1 : 0);
        return;
    }
    int mid = ((l + r) >> 1);
    if (i < mid) {
        update(2 * v + 1, l, mid, i, x);
    } else {
        update(2 * v + 2, mid, r, i, x);
    }
    st[v] = st[2 * v + 1] + st[2 * v + 2];
}

int get(int v, int l, int r, int n) {
    if (r - l == 1) {
        return l + 1;
    }
    int mid = ((l + r) >> 1);
    if (n <= st[2 * v + 1]) {
        return get(2 * v + 1, l, mid, n);
    } else {
        n -= st[2 * v + 1];
        return get(2 * v + 2, mid, r, n);
    }
}

int main() {
    int n;
    cin >> n;
    a.assign(n, 0);
    st.assign(4 * n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build(0, 0, n);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        char op;
        cin >> op;
        if (op == 'u') {
            int i, x;
            cin >> i >> x;
            --i;
            update(0, 0, n, i, x);
        }
        if (op == 's') {
            int i;
            cin >> i;
            if (i > st[0]) {
                cout << "-1 ";
            } else {
                cout << get(0, 0, n, i) << ' ';
            }
        }
    }
    cout << '\n';
    return 0;
}