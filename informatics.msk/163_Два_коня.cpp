#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	string s, f;
	cin >> s >> f;
	vector<vector<int>> d(8, vector<int>(8, 1e6));
	vector<int> dx = { 1, 2, -1, 2, 1, -2, -1, -2}, dy = { 2, 1, 2, -1, -2, 1, -2, -1};
	d[s[0] - 'a'][s[1] - '0' - 1] = 0;
	queue<pair<int, int>> q;
	q.push({s[0] - 'a', s[1] - '0' - 1});
	while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && d[nx][ny] > d[x][y] + 1) {
				d[nx][ny] = d[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	if (d[f[0] - 'a'][f[1] - '0' - 1] % 2 != 0) {
		cout << "-1\n";
	}
	else {
		cout << d[f[0] - 'a'][f[1] - '0' - 1] / 2 << '\n';
	}
	return 0;
}