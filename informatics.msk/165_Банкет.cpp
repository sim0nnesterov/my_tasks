#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ld = long double; 
using pii = pair<int, int>;

const ll INF = 2 * 1e18;
const ld RAM = 1e-9;
const dbl EPS = 1e-7;
const int MOD = 1e7;

bool dfs(vector<vector<int>> g, vector<int> &color, int v) {
    for (auto &i : g[v]) {
        if (!color[i]) {
            color[i] = 3 - color[v];
            if (!dfs(g, color, i)) {
                return false;
            }
        } else if(color[i] == color[v]){
            return false;
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //? freopen("input.txt", "r", stdin);
    //? freopen("output.txt", "w", stdout); 
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> color(n, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v), g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        if (!color[i]) {
            color[i] = 1;
            if (!dfs(g, color, i)) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        if (color[i] == 1) {
            cout << i + 1 <<' ';
        }
    }
    cout << '\n';    
    return 0;
}