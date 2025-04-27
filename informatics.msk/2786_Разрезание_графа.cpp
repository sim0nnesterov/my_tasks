#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct query {
	string s;
	ll u, v;
};


struct DSU {
	vector<ll> root, sz;
	DSU(ll n) {
		root.assign(n, 0);
		for (ll i = 0; i < n; ++i) {
			root[i] = i;
		}
		sz.assign(n, 1);
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
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
#ifdef ARCH_SIM0N
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
	ll n, m, k;
	cin >> n >> m >> k;
	vector<string> ans;
	for (ll i = 0; i < m; ++i) {
		ll u, v;
		cin >> u >> v;
	}
	DSU d(n);
	vector<query> q(k);
	for (ll i = 0; i < k; ++i) {
		cin >> q[i].s >> q[i].u >> q[i].v;
		--q[i].u, --q[i].v;
	}
	for (ll i = k - 1; i >= 0; --i) {
		if (q[i].s == "ask") {
			if (d.get_root(q[i].u) == d.get_root(q[i].v)) {
				ans.push_back("YES");				
			} else {
				ans.push_back("NO");				
			}
		}
		if (q[i].s == "cut") {
			d.unite(q[i].u, q[i].v);
		}
	}
	for (ll i = ans.size() - 1; i >= 0; --i) {
		cout << ans[i] << '\n';
	}
	return 0;
}	
