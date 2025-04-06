#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> used, dist;

bool f = false;

void dfs(int v) {
    used[v] = 1;
    ++dist[v];
    if (f == true && dist[v] == 2) {
        cout << v + 1 << '\n';
        exit(0);
    }
    for (auto &u : g[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    --a, --b;
    g.resize(n);
    used.resize(n, 0);
    dist.resize(n, 0);
    for (int i = 1; i < n; ++i) {
        int v;
        cin >> v;
        --v;
        g[i].push_back(v);
    }
    dfs(a);
    f = true;
    used = vector<int>(n, 0);
    dfs(b);
    return 0;
}