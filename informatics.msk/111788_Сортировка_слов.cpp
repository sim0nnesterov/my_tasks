#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<string> ans_dfs;

struct Trie {
    vector<Trie*> vec;
    ll cnt = 0;
    Trie() : vec(26, nullptr), cnt(0) {}
};

void instrie(Trie* root, const string &s) {
    Trie* v = root;
    for (auto &c : s) {
        ll idx = c - 'a';
        if (!v->vec[idx]) {
            v->vec[idx] = new Trie();
        }
        v = v->vec[idx];
    }
    ++(v->cnt);
}

void dfs(Trie* v, string s) {
    if(v->cnt) {
        for (ll i = 0; i < v->cnt; ++i) {
            ans_dfs.push_back(s);
        }
    }
    for (ll i = 0; i < 26; ++i) {
        if (v->vec[i]) {
            s += 'a' + i;
            dfs(v->vec[i], s);
            s.pop_back();
        }
    }
}

int main() {
    Trie* root = new Trie();
    vector<string> pt;
    string str, q, p;
    cin >> str;
    bool srt = false, fin = false;
    if (str.front() == '.') {
        srt = true;
    }
    if (str.back() == '.') {
        fin = true;
    }
    for (ll i = 0; i < str.size(); ++i) {
        if (str[i] == '.') {
            p += '.';
            if (!q.empty()) {
               ans_dfs.push_back(q);
            }
            q.clear();
        } else {
            q += str[i];
            if (!p.empty()) {
                pt.push_back(p);
                p.clear();
            }
        }
    }
    if (!q.empty()) {
        ans_dfs.push_back(q);
    }
    if (!p.empty()) {
        pt.push_back(p);
    }
    sort(ans_dfs.begin(), ans_dfs.end());
    ll n = pt.size(), m =  ans_dfs.size();
    if (srt && fin) {
        for (ll k = 0; k < min(n, m); ++k) {
            cout << pt[k] << ans_dfs[k];
        }
        cout << pt.back();
    }
    if (!srt && !fin) {
        for (ll k = 0; k < min(n, m); ++k) {
            cout << ans_dfs[k] << pt[k];
        }
        cout << ans_dfs.back();
    }
    if (srt && !fin) {
        for (ll k = 0; k < min(n, m); ++k) {
            cout << pt[k] << ans_dfs[k];
        }
    }
    if (!srt && fin) {
        for (ll k = 0; k < min(n, m); ++k) {
            cout << ans_dfs[k] << pt[k];
        }
    }
    cout << "\n";
    return 0;
}