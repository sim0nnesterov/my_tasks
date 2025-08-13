#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;
    cout << k / (n * (n + 1) / 2) << '\n';
    return 0;
}