#include <bits/stdc++.h>

using namespace std;
using ll = long long;
struct bear
{
    ll f, s, num;
};

bool comp(bear a, bear b) {
    if (a.f != b.f) {
        return a.f < b.f;
    } 
    if (a.s != b.s) {
        return a.s < b.s;
    } else {
        return a.num < b.num;
    }
}

int main() {
    ll n, p;
    cin >> n;
    vector<bear> a;
    vector<ll> res;
    for (ll i = 0; i < n; ++i) {
        ll s, len;
        cin >> s >> len >> p;
        a.push_back({s + len, s, i + 1});
    } 
    sort(a.begin(), a.end(), comp);
    ll prd = 0, ans = 0;
    for (auto [i, j, num] : a) {
        if (j >= prd) {
            ++ans;
            prd = i;
            res.push_back(num);
        }
    }
    cout << ans * p  << '\n' << ans << '\n';
    for (auto i : res) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}