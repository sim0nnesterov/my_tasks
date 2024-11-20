#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<string,int> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < x; ++j) {
            string prd;
            cin >> prd;
            ++m[prd];
        }
    }
    vector<string> ans1, ans2;
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it -> second == n) {
            ans2.push_back(it -> first);
        } 
        if (it -> second >= 1) {
            ans1.push_back(it -> first);
        }
    }
    cout << ans2.size() << '\n';
    for (int i = 0; i < (int)ans2.size(); ++i) {
        cout << ans2[i] << '\n'; 
    }
    cout << ans1.size() << '\n';
    for (int i = 0; i < (int)ans1.size(); ++i) {
        cout << ans1[i] << '\n';
    } 
    return 0;
}