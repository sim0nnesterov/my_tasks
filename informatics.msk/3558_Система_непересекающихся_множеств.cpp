#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct DSU {
	vector<ll> root, sz;
	// DSU(ll n) {
	// 	root.assign(n, 0);
	// 	for (ll i = 0; i < n; ++i) {
	// 		root[i] = i;
	// 	}
	// 	sz.assign(n, 1);
	// }	

	void build(ll n) {
		root.assign(n, 0);
		sz.assign(n, 1);
		for (ll i = 0; i < n; ++i) {
			root[i] = i;
		}
	}

	ll get_root(ll i) {
		if (root[i] == i) {
			return i;
		}
		return root[i] = get_root(root[i]);
	}
	void unite(ll a, ll b) {
		a = get_root(a);
		b = get_root(b);
		if (a == b) {
			return;
		}
		if (sz[a] < sz[b]) {
			swap(a, b);
		}
		root[b] = a;
		sz[a] += sz[b];
	}
};

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
    // cout.tie(nullptr); 
#ifdef ARCH_SIM0N
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
	DSU d;
	string op;
	while (cin >> op) {
		if (op == "RESET") {
			ll n;
			cin >> n;
			d.build(n);
			cout << "RESET DONE\n";
		}
		if (op == "JOIN") {
			ll u, v;
			cin >> u >> v;
			if (d.get_root(u) == d.get_root(v)) {
				cout << "ALREADY " << u << ' ' << v << '\n';
			} else {
				d.unite(u, v);
			}
		}
		if (op == "CHECK") {
			ll u, v;
			cin >> u >> v;
			if (d.get_root(u) == d.get_root(v)) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}
	return 0;
}	