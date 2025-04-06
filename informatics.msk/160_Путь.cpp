#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, s, f, v;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> dist(n, n), parent(n, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> x;
            if (x == 1) {
                g[i].push_back(j);
            }
        }
    } 
    cin >> s >> f;
    --s, --f;
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (auto &u : g[v]) {
            if (dist[u] > dist[v] + 1) {
                dist[u] = dist[v] + 1;
                parent[u] = v;
                q.push(u);
            }
        }
    }
    if (dist[f] == n) {
        cout << "-1\n";
        return 0;
    }
    if (dist[f] == 0) {
        cout << "0\n";
        return 0;
    }
    cout << dist[f] << '\n';
    vector<int> ans;
    ans.push_back(f);
    while (parent[f] != -1) {
        ans.push_back(parent[f]);
        f = parent[f];
    }
    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i] + 1 << ' ';
    }
    cout << '\n';
    return 0;   
}