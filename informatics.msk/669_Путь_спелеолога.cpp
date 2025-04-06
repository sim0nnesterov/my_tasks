#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<int, int>;

const ll MAXN = 1e18;
const int MOD = 1e9 + 7;

struct cord {
    int x, y, z;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
#ifdef ARCH_Sim0n
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<vector<int>>> g(n, vector<vector<int>>(n, vector<int>(n))),
    d(n, vector<vector<int>>(n, vector<int>(n, INT_MAX)));
    vector<cord> step = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
    queue<cord> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                char c;
                cin >> c;
                g[i][j][k] = (c == '#' ? 1 : 0);
                if (c == 'S') {
                    d[i][j][k] = 0;
                    q.push({i, j, k});
                }
            }
        }
    }
    while (!q.empty()) {
        auto &[x, y, z] = q.front();
        q.pop();
        for (auto &[a, b, c] : step) {
            if (x + a >= 0 && x + a < n && y + b >= 0 && y + b < n && z + c >= 0 && z + c < n && g[x + a][y + b][z + c] == 0 && d[x + a][y + b][z + c] > d[x][y][z] + 1) {
                d[x + a][y + b][z + c] = d[x][y][z] + 1;
                q.push({x + a, y + b, z + c});
            }
        } 
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans = min(ans, d[0][i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}           
