#include <bits/stdc++.h>

#define fr first
#define sc second

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<int, int>;

const ll INF = 1e18;
const ld RAM = 1e-9;
const int MOD = 1e9 + 7;
const ld EPS = 1e-18;

bool f = false;

void dfs(const vector<vector<int>> &g, vector<int> &used,vector<int> &path, int v) {
    if (f == true) {
        return;
    }
    used[v] = 1;
    path.push_back(v);
    for (auto u : g[v]) {
        if (used[u] == 1) {
            path.push_back(u);
            f = true;
            return;
        } else {
            dfs(g, used, path, u);
        }
    }
    used[v] = 2;
    path.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
#ifdef ARCH 
    freopen("input.txt", "r", stdin);
    //? freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> used(n, 0), path(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            if (x == 1) {
                g[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(g, used, path, i);
            if (f == true) {
                break;
            }
        }
    }
    if (f == true) {
        int u = path.back();
        cout << "1\n";
    } else {
        cout << "0\n";
    }

    return 0;
}           