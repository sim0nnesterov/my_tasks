#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    multiset<pair<int,int>> ms;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ms.insert({x, i + 1});
    }
    auto it_s = ms.rbegin();
    --it_s;
    int ans = 0;
    vector<pair<int,int>> ans_vec;
    while ((--ms.end()) -> first != 0 && (----ms.end()) -> first != 0) {
        ++ans;
        int a = (--ms.end()) -> second, b = (----ms.end()) -> second, c = (--ms.end()) -> first, d = (----ms.end()) -> first;
        ans_vec.push_back({a, b});
        ms.erase({c, a}), ms.erase({d, b});
        ms.insert({c - 1, a}), ms.insert({d - 1, b});
    }
    cout << ans << '\n';
    for (int i = 0; i < ans; ++i) {
        cout << ans_vec[i].first << ' ' << ans_vec[i].second << '\n';
    }
    return 0;
}