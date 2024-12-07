#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

const ll INF = 1e9;
const ld RAM = 1e-9;
const int MOD = 1e9 + 7;

bool comp(pii a, pii b) {
    if (a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second > b.second;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);  
    //? freopen("input.txt", "r", stdin);
    //? freopen("output.txt", "w", stdout);
    int k, n;
    cin >> k >> n;
    set<int> s;
    vector<int> used(n, 0), ans(n);
    vector<pii> cor;
    for (int i = 1; i <= k; ++i) {
        s.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        cor.emplace_back(l, i), cor.emplace_back(r, i);
    }
    sort(cor.begin(), cor.end(), comp);

    for (int i = 0; i < n * 2; ++i) {
        if (used[cor[i].second] == 0) {
            if (s.empty()) {
                cout << "0 " << cor[i].second + 1 << '\n';
                return 0;
            } 
            auto it = s.begin();
            used[cor[i].second] = *it;
            ans[cor[i].second] = *it;
            s.erase(s.begin());
        } 
        else if(used[cor[i].second] != 0) {
            s.insert(used[cor[i].second]);
            used[cor[i].second] = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}          


//! OS: ArchLinux ~ notebook