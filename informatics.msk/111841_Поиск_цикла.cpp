#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

bool dfs(const vector<vector<int>>& g, vector<int>& prev, vector<int>& used, int v, int parent, pii& ans) {
    used[v] = 1;
    for (int u : g[v]) {
        if (u == parent) continue; 
        if (!used[u]) {
            prev[u] = v;
            if (dfs(g, prev, used, u, v, ans)) {
                return true;
            }
        } else {
            ans = {u, v};
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    
    vector<vector<int>> g(n);
    vector<int> prev(n, -1), used(n, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n ; ++j) {
            int x;
            cin >> x;
            if (x == 1) {
                g[i].push_back(j);
            }
        }
    }
    

    pii ans = {-1, -1};
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            if (dfs(g, prev, used, i, -1, ans)) {
                break;
            }
        }
    }

    if (ans.first == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        vector<int> cycle;
        int x = ans.second;

        cycle.push_back(ans.first);
        for (int v = ans.second; v != ans.first; v = prev[v]) {
            cycle.push_back(v);
        }
        
        cout << cycle.size() << '\n';
        for (int v : cycle) {
            cout << v + 1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}
