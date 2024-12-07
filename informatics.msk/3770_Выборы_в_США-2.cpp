#include <bits/stdc++.h>

using namespace std;
using ll = long long;
bool comp (pair<ll, string> a, pair<ll, string> b) {
    if (a.first != b.first) {
       return a.first > b.first;
    } else {
        return a.second < b.second;
    }   
}

int main() {
    freopen("input.txt", "r", stdin);
    ll n;
    cin >> n;
    string town, name;
    map<string, map<string, ll>> cnt;
    map<string, ll> city, res;
    for (ll i = 0; i < n; ++i) {
        ll amount;
        cin >> town >> amount;
        city[town] = amount;
    }
    while (cin >> town) {
        cin >> name;
        cnt[town][name]++;
        res[name] = 0;
    }
    for (auto &[fir, sec] : cnt) {
        ll maxcnt = 0;
        for (auto &[i, j] : sec) {
            if (maxcnt < j) {
                maxcnt = j;
                name = i;
            } 
            if (maxcnt == j && name > i) {
                name = i;
            }
        }

        res[name] += city[fir];
    }
    vector<pair<ll, string>> ans;
    
    for (auto &[i, j] : res) {
        ans.emplace_back(j, i);
    }
    sort(ans.begin(), ans.end(), comp);
    for (auto &[i, j] : ans) {
        cout << j << ' ' << i << '\n';
    }
    return 0;
}