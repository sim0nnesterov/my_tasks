#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<ll, ll>;
// using lll = __int128_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
#ifdef ARCHL
    freopen("B.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (auto& i : a) {
        cin >> i;
        sum += i;
    }
    ll edge = (sum + 1) / 2;
    sum = 0;
    int l = 0, r = 0, ans = 1000000000;
    while (r < n) {
        if (sum >= edge) {
            ans = min(ans, r - l);
        }
        if (sum < edge) {
            sum += a[r];
            r++;
        } else {
            sum -= a[l];
            l++;
        }
    }
    while (sum >= edge) {
        ans = min(ans, r - l);
        sum -= a[l];
        l++;
    }
    deque<ll> dq;
    l = 0, r = 0;
    sum = 0;
    while (r < n) {
        if (sum - a[dq.front()] >= edge) {
            ans = min(ans, r - l - 1);
        }
        if (sum - a[dq.front()] < edge) {
            while (!dq.empty() && a[dq.back()] >= a[r]) {
                dq.pop_back();
            }
            dq.push_back(r);
            sum += a[r];
            r++;
        } else {
            if (dq.front() == l)
                dq.pop_front();
            sum -= a[l];
            l++;
        }
    }
    while (sum - a[dq.front()] >= edge) {
        ans = min(ans, r - l - 1);
        if (dq.front() == l)
            dq.pop_front();
        sum -= a[l];
        l++;
    }
    cout << ans;
    return 0;
}
