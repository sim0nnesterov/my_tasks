#include <bits/stdc++.h>

using namespace std;

const int INF = 1e3;

int main() {
    int n, x1, x2, y1, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    --x1, --y1, --x2, --y2; 
    vector<vector<int>> d(n, vector<int>(n, INF));
    vector<vector<pair<int, int>>> p(n, vector<pair<int, int>> (n, {-1, -1}));
    d[x1][y1] = 0;
    queue<pair<int, int>> q;
    q.push({x1, y1});
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if (x > 1 && y > 0 && d[x - 2][y - 1] > d[x][y] + 1) { // x - 2, y - 1
            d[x - 2][y - 1] = d[x][y] + 1;
            p[x - 2][y - 1] = {x, y};
            q.push({x - 2, y - 1});
        }
        if (x > 0 && y > 1 && d[x - 1][y - 2] > d[x][y] + 1) { // x - 1, y - 2
            d[x - 1][y - 2] = d[x][y] + 1;
            p[x - 1][y - 2] = {x, y};
            q.push({x - 1, y - 2});
        }
        if (x > 1 && y < n - 1 && d[x - 2][y + 1] > d[x][y] + 1) { // x - 2, y + 1
            d[x - 2][y + 1] = d[x][y] + 1;
            p[x - 2][y + 1] = {x, y};
            q.push({x - 2, y + 1});
        }
        if (x > 0 && y < n - 2 && d[x - 1][y + 2] > d[x][y] + 1) { // x - 1, y + 2
            d[x - 1][y + 2] = d[x][y] + 1;
            p[x - 1][y + 2] = {x, y};
            q.push({x - 1, y + 2});
        }
        if (x < n - 1 && y > 1 && d[x + 1][y - 2] > d[x][y] + 1) { // x + 1, y - 2
            d[x + 1][y - 2] = d[x][y] + 1;
            p[x + 1][y - 2] = {x, y};
            q.push({x + 1, y - 2});
        }
        if (x < n - 2 && y > 0 && d[x + 2][y - 1] > d[x][y] + 1) { // x + 2, y - 1
            d[x + 2][y - 1] = d[x][y] + 1;
            p[x + 2][y - 1] = {x, y};
            q.push({x + 2, y - 1});
        }
        if (x < n - 1 && y < n - 2 && d[x + 1][y + 2] > d[x][y] + 1) { // x + 1, y + 2
            d[x + 1][y + 2] = d[x][y] + 1;
            p[x + 1][y + 2] = {x, y};
            q.push({x + 1, y + 2});
        }
        if (x < n - 2 && y < n - 1 && d[x + 2][y + 1] > d[x][y] + 1) { // x + 2, y + 1
            d[x + 2][y + 1] = d[x][y] + 1;
            p[x + 2][y + 1] = {x, y};
            q.push({x + 2, y + 1});
        } 
    }
    if (d[x2][y2] == INF) {
        cout << "-1\n";
        return 0;
    }
    cout << d[x2][y2] << '\n';
    vector<pair<int, int>> ans;
    ans.push_back({x2, y2});
    while (p[x2][y2] != make_pair(-1, -1)) {
        ans.push_back(p[x2][y2]);
        int a = p[x2][y2].first, b = p[x2][y2].second;
        x2 = a, y2 = b;
    }
    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
    }
    return 0;   
}