//мотивация нада поднять
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    vector<string> ans;
    map<string, int> mp;
    string s;
    while (cin >> s) {
        ++mp[s];
    }
    int res = 0;
    for (auto &[i, j] : mp) {
        if (j > res) {
            res = j, s = i;
        }
    }
    cout << s << '\n';
}
