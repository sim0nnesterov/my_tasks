#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<int, int>;

const ll MAXN = 1e18;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
#ifdef ARCH_Sim0n
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 2, vector<int>(m + 2, 1)), d(n + 2, vector<int>(m + 2, INT_MAX));
    vector<pii> cord, step = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> g[i][j];
            if (g[i][j] == 2) {
                cord.push_back({i, j});
            }
        }
    }    
    d[1][1] = 0;
    queue<pii> q;
    q.push({1, 1});
    while (!q.empty()) {
        pii v = q.front();
        q.pop();
        for (auto &[a, b] : step) {
            auto [x, y] = v; 
            while (g[x + a][y + b] == 0 && x + a >= 1 && y + b >= 1 && x + a <= n && y + b <= m) {
                x += a;
                y += b;
            }
            if (g[x + a][y + b] == 1 && d[x][y] > d[v.first][v.second] + 1) {
                d[x][y] = d[v.first][v.second] + 1;
                q.push({x, y});
            }
            if (g[x + a][y + b] == 2 && d[x + a][y + b] > d[v.first][v.second] + 1) {
                d[x + a][y + b] = d[v.first][v.second] + 1;
                q.push({x + a, y + b});
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < cord.size(); ++i) {
        ans = min(ans, d[cord[i].first][cord[i].second]);
    }
    cout << ans << '\n';
    return 0;
}           