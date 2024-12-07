#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct bear
{
    ll f, s, num;
};

bool comp(bear a, bear b) {
    if (a.f != b.f) {
        return a.f < b.f;
    } 
    if (a.s != b.s) {
        return a.s < b.s;
    } else {
        return a.num < b.num;
    }
}

int main() {
    int l, n, m;
    cin >> l >> n >> m;
    vector<bear> a;
    for (int i = 0; i < n; ++i) {
        int s, f;
        cin >> s >> f;
        a.push_back({s, -1, -1});
        a.push_back({f, 1, -1});
    }
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        a.push_back({x, 0, i});
    }
    sort(a.begin(), a.end(), comp);
    int cnt = 0;
    vector<int> res(m);
    for (int i = 0; i < (int)a.size(); ++i) {
        cnt += a[i].s;
        if (a[i].s == 0) {
            res[a[i].num] = -cnt;
        }
    }
    for (auto i : res) {
        cout << i <<  '\n';
    }
    return 0;
}