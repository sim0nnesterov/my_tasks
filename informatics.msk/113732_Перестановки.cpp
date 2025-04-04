#include <bits/stdc++.h>

using namespace std;

struct node {
    vector<int> v;
};

vector<int> a;
vector<node> st;

vector<int> merge(const vector<int> &a, const vector<int> &b){
    int i = 0, j = 0, n = a.size(), m = b.size();
    vector<int> res;
    while(i != n && j != m){
        if(a[i] < b[j]){
            res.emplace_back(a[i]);
            i++;
        }
        else{
            res.emplace_back(b[j]);
            j++;
        }
    }
    for (; i < n; i++)
    {
        res.emplace_back(a[i]);
    }
    for (; j < m; j++)
    {
        res.emplace_back(b[j]);
    }    
    return res;
}   

void bld(int v, int l, int r) {
    if (r - l == 1) {
        st[v].v.push_back(a[l]);
        return;
    }
    int mid = (r + l) / 2;
    bld(2 * v + 1, l, mid);
    bld(2 * v + 2, mid, r);
    st[v].v = merge(st[2 * v + 1].v, st[2 * v + 2].v);
}

int bin_srch_ans(const vector<int> &a, int x, int y) {
    int srt, fin, l = -1, r = a.size() - 1, mid;
    if (a.front() > y || a.back() < x) {
        return 0;
    }
    while (r - l > 1) {
        mid = (l + r) / 2;
        if (a[mid] >= x) {
            r = mid;
        } else {
            l = mid;
        }
    }
    srt = r;
    l = 0, r = a.size();
    while (r - l > 1) {
        mid = (l + r) / 2;
        if (a[mid] > y) {
            r = mid;
        } else {
            l = mid;
        }
    }
    fin = l;
    return fin - srt + 1;
}

int get(int v, int l, int r, int ql, int qr, int x, int y) {
    if (ql <= l && r <= qr) {
        return bin_srch_ans(st[v].v, x, y);
    }
    if (qr <= l || r <= ql) {
        return 0;
    }
    int mid = (l + r) / 2;
    return get(2 * v + 1, l, mid, ql, qr, x, y) + get(2 * v + 2, mid, r, ql, qr, x, y);
}

int main() {
    int n, m;
    cin >> n >> m;
    a.resize(n);
    st.resize(4 * n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    bld(0, 0, n);
    for (int i = 0; i < m; ++i) {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        --l;
        cout << get(0, 0, n, l, r, x, y) << '\n';
    }
    return 0;
}