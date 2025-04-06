#include <bits/stdc++.h>

using namespace std;

int main() {
    int s, f;
    cin >> s >> f;
    vector<int> d(1e4, INT_MAX), p(1e4, -1);
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front(), fn = v / 1e3, en = v % 10, a = (v - fn * 1e3) * 10 + fn, b = (v - en) / 10 + en * 1e3;
        q.pop();
        if (v / 1e3 != 9 && d[v + 1e3] > d[v] + 1) {
            d[v + 1e3] = d[v] + 1;
            p[v + 1e3] = v;
            q.push(v + 1e3);
        }   
        if (v % 10 != 1 && d[v - 1] > d[v] + 1) {
            d[v - 1] = d[v] + 1;
            p[v - 1] = v;
            q.push(v - 1);
        }
        if (d[a] > d[v] + 1) {
            d[a] = d[v] + 1;
            p[a] = v;
            q.push(a);
        }
        if (d[b] > d[v] + 1) {
            d[b] = d[v] + 1;
            p[b] = v;
            q.push(b);
        }
    }
    vector<int> ans;    
    ans.push_back(f);
    while (p[f] != -1) {
        ans.push_back(p[f]);
        f = p[f];
    }
    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i] << '\n';
    }
    return 0;
}