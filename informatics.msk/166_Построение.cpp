#include <bits/stdc++.h>
using namespace std;
 
vector<int>used, ans;
vector<vector<int>>v;
int after = 0;
 
void dfs(int x){
    
    used[x] = 1;
    
    for(auto &t : v[x]) {        
        if(used[t] == 1) {
            after = 1;
            return;
            
        } else if(!used[t]) {
            dfs(t);
        } 
    }
    used[x] = 2;
}
 
 
void top_sort(int x){
    used[x] = 1;
    for(auto &t : v[x]) {
        if(!used[t]) {
            top_sort(t);
        }
    }
    ans.push_back(x);
}
 
int main()
{
    int n, m;
    cin >> n >> m;
    used.resize(n);
    v.resize(n);
    set<pair<int,int>>st;
    for(int i = 0; i < m; ++i) {
        int f, s;
        cin >> f >> s;
        if(f == s) { 
            continue;
        }
        if(st.find(make_pair(f,s)) != st.end()) {
            continue;
        }
        else {
            st.insert(make_pair(f,s));
        }
        v[f-1].push_back(s-1);
    }
    for(int i = 0;i < n; ++i){
        if(!used[i]) {
            dfs(i);
        }
        if(after) {
            cout << "No\n";
            return 0;
        }
    }
    used.clear();
    used.resize(n);
    for(int i = 0; i < n; ++i){
        if(!used[i]) {
            top_sort(i);
        }
    }
    cout << "Yes\n";
    for(int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i] + 1 << ' ';
    }
    cout << '\n';
    
    return 0;
}