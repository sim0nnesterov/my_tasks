#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> g;
vector<int> used;
vector<vector<int>> otvet;

int col = -1;

void dfs(int i) {
    used[i] = 1;
    otvet[col].push_back(i + 1);
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
    otvet = vector<vector<int>>(n);
    for (int i = 0; i < m ; ++i) {
        int s, f;
        cin >> s >> f;
        --s, --f;
        g[s].push_back(f);
        g[f].push_back(s);
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            ++col;
            dfs(i);
        }
    }

    cout << col + 1 << '\n';
    for (int i = 0; i <= col; ++i) {
        cout << otvet[i].size() << '\n';
        for (int j = 0; j < (int)otvet[i].size(); ++j) {
            cout << otvet[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}