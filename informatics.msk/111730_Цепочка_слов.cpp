
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using dbl = double;
using pii = pair<ll, ll>;
// using lll = __int128_t;

const ll MAXN = 1e18;
const int MOD = 1e9 + 7;

struct Trie {
    ll cnt;
    vector<Trie*> go;    
    Trie() {
        cnt = 0;
        go.assign(26, nullptr);
    }
};

void insTrie(string &s, Trie* root) {
    Trie* v = root;
    for (auto &c : s) {
        ll idx = c - 'a';
        if (!v->go[idx]) {
            v->go[idx] = new Trie();
        }    
        v = v->go[idx];
    }
    if (!v->cnt) {
        ++v->cnt;
    }
}

ll ans = 0, cnt = 0;

void dfs(Trie* root) {
    cnt += root->cnt;
    ans = max(cnt, ans);
    for (ll i = 0; i < 26; ++i) {
        if (root->go[i]) {
            dfs(root->go[i]);
        }
    }
    cnt -= root->cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
#ifdef ARCH_Sim0n
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    Trie* root = new Trie();
    for (ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        insTrie(s, root);
    }
    dfs(root);
    cout << ans << '\n';
    return 0;
}         