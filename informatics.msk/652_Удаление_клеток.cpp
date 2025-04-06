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

int n, m;

void dfs(const vector<vector<char>> &mrx, vector<vector<int>> &used, int i, int j) {
    used[i][j] = 1;
    if (i > 0 && mrx[i - 1][j] == '#' && used[i - 1][j] == 0) {
        dfs(mrx, used, i - 1, j);
    }
    if (i + 1 < n && mrx[i + 1][j] == '#' && used[i + 1][j] == 0) {
        dfs(mrx, used, i + 1, j);
    }
    if (j > 0 && mrx[i][j - 1] == '#' && used[i][j - 1] == 0) {
        dfs(mrx, used, i, j - 1);
    }
    if (j + 1 < m && mrx[i][j + 1] == '#' && used[i][j + 1] == 0) {
        dfs(mrx, used, i, j + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
#ifdef ARCH 
    freopen("input.txt", "r", stdin);
    //? freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m;
    vector<vector<char>> mrx(n, vector<char>(m));
    vector<vector<int>> used(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mrx[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mrx[i][j] == '#' && used[i][j] == 0) {
                ++ans;
                dfs(mrx, used, i, j);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}           
