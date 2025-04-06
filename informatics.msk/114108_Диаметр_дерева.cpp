#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> used, dist;
int cnt = 0;

void dfs(int v) {
    dist[v] = cnt;
    used[v] = 1;
    for (auto &u : g[v]) {
        if (!used[u]) {
            ++cnt;
            dfs(u);
        }
    }
    --cnt;
}

int main() {
    int n;
    cin >> n;
    g.resize(n);
    used.resize(n, 0);
    dist.resize(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    int m = max_element(dist.begin(), dist.end()) - dist.begin();
    used = vector<int>(n, 0), dist = vector<int>(n, 0);
    cnt = 0;
    dfs(m);
    cout << *max_element(dist.begin(), dist.end()) << '\n';
    return 0;
}