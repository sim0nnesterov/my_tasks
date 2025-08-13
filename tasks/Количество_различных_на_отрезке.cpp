/*
⡏⠉⠉⠉⠉⠉⠉⠋⠉⠉⠉⠉⠉⠉⠋⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠙⠉⠉⠉⠹
⡇⢸⣿⡟⠛⢿⣷⠀⢸⣿⡟⠛⢿⣷⡄⢸⣿⡇⠀⢸⣿⡇⢸⣿⡇⠀⢸⣿⡇⠀
⡇⢸⣿⣧⣤⣾⠿⠀⢸⣿⣇⣀⣸⡿⠃⢸⣿⡇⠀⢸⣿⡇⢸⣿⣇⣀⣸⣿⡇⠀
⡇⢸⣿⡏⠉⢹⣿⡆⢸⣿⡟⠛⢻⣷⡄⢸⣿⡇⠀⢸⣿⡇⢸⣿⡏⠉⢹⣿⡇⠀
⡇⢸⣿⣧⣤⣼⡿⠃⢸⣿⡇⠀⢸⣿⡇⠸⣿⣧⣤⣼⡿⠁⢸⣿⡇⠀⢸⣿⡇⠀
⣇⣀⣀⣀⣀⣀⣀⣄⣀⣀⣀⣀⣀⣀⣀⣠⣀⡈⠉⣁⣀⣄⣀⣀⣀⣠⣀⣀⣀⣰

⡿⣡⣿⣿⡟⡼⡁⠁⣰⠂⡾⠉⢨⣿⠃⣿⡿⠍⣾⣟⢤⣿⢇⣿⢇⣿⣿⢿
⣱⣿⣿⡟⡐⣰⣧⡷⣿⣴⣧⣤⣼⣯⢸⡿⠁⣰⠟⢀⣼⠏⣲⠏⢸⣿⡟⣿
⣿⣿⡟⠁⠄⠟⣁⠄⢡⣿⣿⣿⣿⣿⣿⣦⣼⢟⢀⡼⠃⡹⠃⡀⢸⡿⢸⣿
⣿⣿⠃⠄⢀⣾⠋⠓⢰⣿⣿⣿⣿⣿⣿⠿⣿⣿⣾⣅⢔⣕⡇⡇⡼⢁⣿⣿
⣿⡟⠄⠄⣾⣇⠷⣢⣿⣿⣿⣿⣿⣿⣿⣭⣀⡈⠙⢿⣿⣿⡇⡧⢁⣾⣿⣿
⣿⡇⠄⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢻⠇⠄⠄⢿⣿⡇⢡⣾⣿⣿⣿
⣿⣷⢰⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⢰⣧⣀⡄⢀⠘⡿⣰⣿⣿⣿⣿⣿
⢹⣿⢸⣿⣿⠟⠻⢿⣿⣿⣿⣿⣿⣿⣿⣶⣭⣉⣤⣿⢈⣼⣿⣿⣿⣿⣿⣿
⢸⠇⡜⣿⡟⠄⠄⠄⠈⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟⣱⣻⣿⣿⣿⣿⣿⠟⠁
⠄⣰⡗⠹⣿⣄⠄⠄⠄⢀⣿⣿⣿⣿⣿⣿⠟⣅⣥⣿⣿⣿⣿⠿⠋⠄⠄⣾
⠜⠋⢠⣷⢻⣿⣿⣶⣾⣿⣿⣿⣿⠿⣛⣥⣾⣿⠿⠟⠛⠉⠄⠄
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<ll, ll>;
// using lll = __int128_t;

const ll MAXN = 1e18;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll K = 350;

struct query {
	ll l, r, idx;
	query() {}
	query(ll l, ll r, ll idx) : l(l), r(r), idx(idx) {}
	bool operator<(const query &q) const {
		return r < q.r;
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
#ifdef ARCH_Sim0n
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ll n, m;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cin >> m;
    vector<ll> ans(m);
	vector<ll> c = v;
	sort(c.begin(), c.end());
	c.resize(unique(c.begin(), c.end()) - c.begin());
	for (auto &el : v) {
		el = lower_bound(c.begin(), c.end(), el) - c.begin();
    }
	vector<ll> cntv(c.size(), 0);
	ll len = sqrt(n), tot, cnt = (n + len - 1) / len;
	vector<vector<query>> Qry(cnt);
	for (ll q = 0; q < m; ++q) {
        char ch;
		ll l, r;
        cin >> ch >> l >> r;
        --l, --r;
		tot = 0;
		if (r - l + 1 <= len) {
			for (ll i = l; i <= r; ++i) {
				++cntv[v[i]];
				tot += cntv[v[i]] == 1;
			}
			ans[q] = tot;
			for (ll i = l; i <= r; ++i) {
				cntv[v[i]] = 0;
            }
		}
		else {
			Qry[l / len].emplace_back(l, r, q);
        }
	}
	for (ll i = 0; i < cnt - 1; ++i) {
		sort(Qry[i].begin(), Qry[i].end());
		ll _r = (i + 1) * len;
		ll _l = _r - 1;
		++cntv[v[_l]];
		tot = 1;
		for (auto &q : Qry[i]) {
			for (; _r <= q.r; ++_r) {
				++cntv[v[_r]];
				tot += cntv[v[_r]] == 1;
			}
			for (; _l > q.l; --_l) {
				++cntv[v[_l - 1]];
				tot += cntv[v[_l - 1]] == 1;
			}
			for (; _l < q.l; ++_l) {
				--cntv[v[_l]];
				tot -= cntv[v[_l]] == 0;
			}
			ans[q.idx] = tot;
		}
		for (ll i = _l; i < _r; ++i) {
			cntv[v[i]] = 0;
        }
	}
    for (auto &el : ans) {
        cout << el << '\n';
    }
    return 0;
}   