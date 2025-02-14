#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m)), dist(n, vector<int>(m, n + m + 1));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
            if (g[i][j]) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();
        if (v.first > 0 && dist[v.first - 1][v.second] > dist[v.first][v.second] + 1) {
            dist[v.first - 1][v.second] = dist[v.first][v.second] + 1;
            q.push({v.first - 1, v.second});
        }        
        if (v.first < n - 1 && dist[v.first + 1][v.second] > dist[v.first][v.second] + 1) {
            dist[v.first + 1][v.second] = dist[v.first][v.second] + 1;
            q.push({v.first + 1, v.second});
        }
        if (v.second > 0 && dist[v.first][v.second - 1] > dist[v.first][v.second] + 1) {
            dist[v.first][v.second - 1] = dist[v.first][v.second] + 1;
            q.push({v.first, v.second - 1});
        }
        if (v.second < m - 1 && dist[v.first][v.second + 1] > dist[v.first][v.second] + 1) {
            dist[v.first][v.second + 1] = dist[v.first][v.second] + 1;
            q.push({v.first, v.second + 1});
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;   
}