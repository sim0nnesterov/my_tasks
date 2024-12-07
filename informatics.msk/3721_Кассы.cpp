#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n, cnt = 0;
    cin >> n;
    vector<pair<ll, ll>> a;
    a.emplace_back(0, 0);
    for (ll i = 0; i < n; ++i) {
        ll sh, sm, ss, fh, fm, fs, res1, res2;
        cin >> sh >> sm >> ss >> fh >> fm >> fs;
        res1 = sh * 3600 + sm * 60 + ss, res2 = fh * 3600 + fm * 60 + fs;
        if (res1 == res2) {
            ++cnt;
        } 
         else {
            if (res1 > res2) {
                ++cnt;
            }
            a.emplace_back(res1, -1);
            a.emplace_back(res2, 1);
        }
    } 
    a.emplace_back(24 * 3600, 0);
    sort(a.begin(), a.end());
    ll srt = -1, fin = -1, ans = 0;
    for (auto [i, j] : a) {
        cnt -= j;
        if (cnt == n && srt == -1) {
            srt = i;
        } 
        if (cnt == n && srt != -1) {
            fin = i;
        }
        if (cnt < n && srt != -1) {
            fin = i;
            ans += fin - srt;
            srt = -1, fin = -1;
        }
    }
    if (cnt == n && srt != -1) {
            fin = (*a.rbegin()).first;
            ans += fin - srt;
            srt = -1, fin = -1;
    }
    cout << ans << '\n';
    return 0;
}