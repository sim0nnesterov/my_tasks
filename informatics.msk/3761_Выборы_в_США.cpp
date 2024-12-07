//мотивация нада поднять
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    string s;
    int x;
    map<string, int> mp;
    while (cin >> s) {
        cin >> x;
        mp[s] += x;
    }
    for (auto &[key, val] : mp) {
        cout << key << ' ' << val << '\n';
    }
    return 0;
}