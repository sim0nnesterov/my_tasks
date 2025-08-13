#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Evnt {
	ll x, t, y1, y2;
};

struct Node {
	ll val, sz, add;
};

vector<Node> st;
vector<ll> cord;

bool cmp(const Evnt& a, const Evnt& b) {
	if (a.x != b.x) {
		return a.x < b.x;
	}
	if (a.t != b.t) {
		return a.t < b.t;
	}
	if (a.y1 != b.y1) {
		return a.y1 < b.y1;
	}
	return a.y2 < b.y2;
}

Node gtminNode(const Node& a, const Node& b) {
	Node ans = {0, 0, 0};
	if (a.val < b.val) {
		ans.val = a.val;
		ans.sz = a.sz;
	}
	if (a.val > b.val) {
		ans.val = b.val;
		ans.sz = b.sz;
	} 
	if (a.val == b.val) {
		ans.val = a.val;
		ans.sz = a.sz + b.sz;	
    }
	return ans;
}

void build(ll v, ll l, ll r) {
	if (r - l == 1) {
		st[v].sz = cord[r] - cord[l];
		return;
	}
	ll mid = (l + r) / 2;
	build(2 * v + 1, l, mid);
	build(2 * v + 2, mid, r);
	st[v] = gtminNode(st[2 * v + 1], st[2 * v + 2]);
}
void apply(ll v, ll l, ll r, ll x) {
	st[v].val += x;
	st[v].add += x;
}
void push(ll v, ll l, ll r) {
	ll mid = (l + r) / 2;
	apply(2 * v + 1, l, mid, st[v].add);
	apply(2 * v + 2, mid, r, st[v].add);
	st[v].add = 0;
}
void update(ll v, ll l, ll r, ll ql, ll qr, ll x) {
    	if (ql <= l && r <= qr) {
		apply(v, l, r, x);
		return;
	}
	if (qr <= l || r <= ql) {
		return;
	}
	push(v, l, r);
	ll mid = (l + r) / 2;
	update(2 * v + 1, l, mid, ql, qr, x);
	update(2 * v + 2, mid, r, ql, qr, x);
	st[v] = gtminNode(st[2 * v + 1], st[2 * v + 2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
#ifdef ARCH_SIM0N
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
	ll n;
	cin >> n;
	vector<Evnt> ev;
	for (ll i = 0; i < n; ++i) {
        ll x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ev.push_back({x1, -1, y1, y2});
        ev.push_back({x2, 1, y1, y2});
        cord.push_back(y1);
        cord.push_back(y2);
	}
	sort(cord.begin(), cord.end());	cord.erase(unique(cord.begin(), cord.end()), cord.end());
	sort(ev.begin(), ev.end(), cmp);
	st.assign(4 * (cord.size() - 1), {0, 0, 0});
	build(0, 0, cord.size() - 1);
	Evnt pred = *ev.begin();
	ll m = cord.size() - 1, ans = 0, w = cord.back() - *cord.begin();
	for (auto &[x, t, y1, y2] : ev) {
		ll r = lower_bound(cord.begin(), cord.end(), y2) - cord.begin(),
		l = lower_bound(cord.begin(), cord.end(), y1) - cord.begin();
		ans += (st[0].val == 0 ? w - st[0].sz : w) * (x - pred.x);
		update(0, 0, m, l, r, -t);
		pred = {x, t, y1, y2};
	}
	cout << ans << '\n';
	return 0;
}