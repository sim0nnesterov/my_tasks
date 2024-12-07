//мотивация нада поднять
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    set<int> s;
    for (int i = 1; i <= 1000000; ++i) {
        s.insert(i);
    }
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x < 0) {
            s.insert(-x);
        } else {
            cout << *s.lower_bound(x) << '\n';
            s.erase(s.lower_bound(x));
        }
    }
    return 0;
}

//abobas