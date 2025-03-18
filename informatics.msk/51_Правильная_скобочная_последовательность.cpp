#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
            st.push(s[i]);
        } else {
            if (s[i] == ')' && st.size() && st.top() == '(') {
                st.pop();
            }
            else if (s[i] == '}' && st.size() && st.top() == '{') {
                st.pop();
            }
            else if (s[i] == ']' && st.size() && st.top() == '[') {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
    }
    if (st.empty()) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
    return 0;
}
