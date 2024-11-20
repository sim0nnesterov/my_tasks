#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    multiset <int> ms;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ms.insert(x);
    }
    while (!ms.empty()) {
        multiset<int>::iterator it = ms.begin();  
        cout << *it << '\n';
        ms.erase(it), ms.erase(ms.find(*it / 3 * 4));
    }
    return 0;
}