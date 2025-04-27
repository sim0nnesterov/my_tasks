#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct DSU {
	vector<ll> p, sz, ct;
	DSU(ll n) {
		p.assign(n, 0);
		for (ll i = 0; i < n; ++i) {
			p[i] = i;
		}
		sz.assign(n, 1);
		ct.assign(n, 0);
	}	
	ll get_p(ll i) {
		if (p[i] == i) {
			return i;
		}
		return p[i] = get_p(p[i]);
	}
	void unite(ll a, ll b, ll w) {
		a = get_p(a);
		b = get_p(b);
		if (a == b) {
			ct[a] += w;
			return;
		}
		if (sz[a] < sz[b]) {
			swap(a, b);
		}
		ct[a] += w + ct[b];
		p[b] = a;
		sz[a] += sz[b];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
#ifdef ARCH_SIM0N
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
	ll n, m;
	cin >> n >> m;
	DSU d(n);
	for (ll i = 0; i < m; ++i) {
		ll op;
		cin >> op;
		if (op == 1) {
			ll x, y, w;
			cin >> x >> y >> w;
			--x, --y;
			d.unite(x, y, w);
		}
		if (op == 2) {
			ll x;
			cin >> x;
			--x;
			cout << d.ct[d.get_p(x)] << '\n';
		}
	}
	return 0;
}