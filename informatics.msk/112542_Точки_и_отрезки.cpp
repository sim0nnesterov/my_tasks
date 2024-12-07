#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ld = long double; 
using pii = pair<int, int>;

const int INF = 1e7;
const ld RAM = 1e-9;
const dbl EPS = 1e-7;
const int MOD = 1e7;

struct trio {
    int fir;
    int sec;
    int num;
};
bool comp(trio a, trio b) {
    if (a.fir != b.fir) {
        return a.fir < b.fir;
    } else if (a.sec != b.sec) {
        return a.sec < b.sec;
    } else {
        return a.num > b.num;
    }
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);  
    //? freopen("input.txt", "r", stdin);
    //? freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<trio> a;
    vector<int> b(m);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        a.push_back({min(l, r), 1, -1}), a.push_back({max(l, r), 3, -1});
    }
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        a.push_back({x, 2, i});
    }
    sort(a.begin(), a.end(), comp);
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i].sec == 1) {
            ++cnt;
        }
        else if (a[i].sec == 3) {
            --cnt;
        }
        else if (a[i].sec == 2) {
            b[a[i].num] = cnt;
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << b[i] << ' ';
    }
    cout << '\n';
    return 0;
}          

//! OS: ArchLinux ~ notebook

//abobas