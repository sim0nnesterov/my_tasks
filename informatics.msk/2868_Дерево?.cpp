#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> g;
vector<int> used;

void dfs(int i) {
    used[i] = 1;
    for (auto j : g[i]) {
        if(!used[j]) {
            dfs(j);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    g = vector<vector<int>> (n);
    used = vector<int> (n, 0);
    for (int i = 0; i < m ; ++i) {
        int s, f;
        cin >> s >> f;
        --s, --f;
        g[s].push_back(f);
        g[f].push_back(s);
    }
    dfs(0);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += used[i];
    }
    if (cnt == n && n == m + 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
