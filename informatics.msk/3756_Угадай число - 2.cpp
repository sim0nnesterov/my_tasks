#include <bits/stdc++.h>

using namespace std;

void parse(string s, unordered_set<int> &ans) {
    s += ' ';
    int prd = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] != ' ') {
            prd = prd * 10 + (s[i] - '0');
        } else {
            ans.insert(prd);
            prd = 0;
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    int a;
    string s;
    cin >> a;
    getline(cin, s);
    unordered_set<int> mnogo, ans, y;
    for (int i = 1; i <= a; ++i) {
        mnogo.insert(i);
    }
    while (getline(cin, s)) {
        if (s == "HELP") break;
        ans.clear();
        parse(s, ans);
        y.clear();
        for (auto i : ans) {
            if (mnogo.count(i)) {
                y.insert(i);
            }
        }
        if (y.size() > mnogo.size() - y.size()) {
            cout << "YES\n";
            mnogo = y;
        } else {
            cout << "NO\n";
            for (auto &i : ans) {
                mnogo.extract(i);
            }
        }
    }
    vector<int> otvet;
    for (auto &i : mnogo) {
        otvet.emplace_back(i);
    }
    sort(otvet.begin(), otvet.end());
    for (auto &i : otvet) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}