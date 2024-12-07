#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> events;
    for (int i = 0; i < n; ++i) {
        long long start, end;
        cin >> start >> end;
        events.emplace_back(start, 1);
        events.emplace_back(end + 1, -1);
    }

    sort(events.begin(), events.end());
    ll ans = 0,  prd = 0, cnt = 0; 
    for (auto &eve : events) {
        if (cnt > 0) {
            ans += eve.first - prd;
        }
        cnt += eve.second;
        prd = eve.first;
    }
    cout << ans << '\n';
    return 0;
}

//abobas