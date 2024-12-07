#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    multiset<double> ms;
    for (int i = 0; i < n; ++i) {
        double x;
        cin >> x;
        ms.insert(x);
    }
    double ans = 0;
    while (ms.size() > 1) {
        auto it = ms.begin();
        double res = *it + *(++it);
        --it;
        ans += res / 100 * 5;
        ms.erase(ms.begin()), ms.erase(ms.begin());
        ms.insert(res);
    }
    cout << fixed << setprecision(2) << ans << '\n';
    return 0;
}

//abobas