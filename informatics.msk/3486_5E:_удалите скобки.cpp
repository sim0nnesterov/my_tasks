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
    cout << st.size() << '\n';
    return 0;
}
