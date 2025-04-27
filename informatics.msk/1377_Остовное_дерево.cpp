#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Edge {
	ll u, v, w;
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

bool cmp(Edge a, Edge b) {
	return a.w < b.w;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
#ifdef ARCH_SIM0N
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
	ll n, m, ans = 0;
	cin >> n >> m;
	vector<Edge> g(m);
	DSU d(n);
	for (ll i = 0; i < m; ++i) {
		cin >> g[i].u >> g[i].v >> g[i].w;
		--g[i].u, --g[i].v;
	}
	sort(g.begin(), g.end(), cmp);
	for (auto &[u, v, w] : g) {
		if (d.get_root(u) != d.get_root(v)) {
			ans += w;
			d.unite(u, v);
		}
	}
	cout << ans << '\n';
	return 0;
}	