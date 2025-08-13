#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<int, int>;

struct point {
    ll x, y;
};

bool cw(point a, point b, point c) {
    ll tot = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
    return tot > 0;
}

bool ccw(point a, point b, point c) {
    ll tot = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
    return tot < 0;
}

bool comp(point a, point b) {
    if (a.x != b.x) {
        return a.x < b.x;
    }
    return a.y < b.y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
// #ifdef ARCH_Sim0n
    freopen("hullp.in", "r", stdin);
    freopen("hullp.out", "w", stdout);
// #endif  
    cout << fixed << setprecision(16);
    ll n;
    cin >> n;
    vector<point> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a.begin(), a.end(), comp);
    vector<point> up = {a[0]}, down = {a[0]};
    point p1 = a[0], p2 = a.back();
    for (ll i = 1; i < a.size(); ++i) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() > 1 && !cw(up[up.size() - 2], up[up.size() - 1], a[i])) {
                up.pop_back();
            }
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while (down.size() > 1 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i])) {
                down.pop_back();
            }
            down.push_back(a[i]);
        }
    }
    vector<point> ans;
    for (auto &el : up) {
        ans.push_back(el);
    }
    for (ll i = down.size() - 2; i >= 0; --i) {
        ans.push_back(down[i]);
    }
    ld tot = 0;
    for (ll i = 0; i < ans.size() - 1; ++i) {
        tot += ld(hypot(ans[i + 1].x - ans[i].x, ans[i + 1].y - ans[i].y));
    }
    cout << tot << '\n';
    return 0;
}