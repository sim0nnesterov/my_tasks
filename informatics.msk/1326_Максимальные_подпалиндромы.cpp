#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int p = 251, mod = 1e9 + 7;

struct Mint {
    int x;

    Mint() : x(0) {}

    Mint(int x) : x(x) {}

    Mint operator+(const Mint& y) const {
        int c = x + y.x;
        if (c >= mod) c -= mod;
        return c;
    }

    Mint operator-(const Mint& y) const {
        int c = x - y.x;
        if (c < 0) c += mod;
        return c;
    }

    Mint operator*(const Mint& y) const  {
        return Mint((ll)x * y.x % mod);
    }
};

struct Hasher {
    vector<Mint> hash, power;
    // hash[i] - [0, i)

    Hasher(string& s) : hash(s.size() + 1), power(s.size() + 1) {
        hash[0] = 0;
        power[0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            power[i] = power[i - 1] * p;
            hash[i] = hash[i - 1] * p + s[i - 1];
        }
    }

    int get(int l, int r) {
        return (hash[r] - hash[l] * power[r - l]).x;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s, rs;
    cin >> s;
    int n = s.size();
    rs = s;
    reverse(rs.begin(), rs.end());
    Hasher hs(s), hrs(rs);
    for (int i = 0; i < n; ++i) {
        int l = 0, r = i + 1;
        while (r - l > 1) {
            int mid = (r + l) / 2;
            if (hs.get(i - mid, i + mid + 1) == hrs.get(n - 1 - i - mid, n - i + mid)) {
                l = mid; 
            } else {
                r = mid;
            }
        } 
        cout << 2 * l + 1 << ' ';
    } 
    cout << '\n';
    return 0;
}
