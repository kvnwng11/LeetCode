class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int curr = 0;
        char op = '+';

        for (int i=0; i<s.size(); ++i) {
            if (isdigit(s[i])) {
                curr = 10*curr + (s[i] - '0');
            }
            if (!isdigit(s[i]) and s[i] != ' ' or i == s.size()-1) {
                if (op == '+')
                    st.push(curr);
                else if (op == '-')
                    st.push(-curr);
                else {
                    int ans = 0;
                    if (op == '*')
                        ans = st.top() * curr;
                    else
                        ans = st.top() / curr;
                    st.pop();
                    st.push(ans);
                }
                op = s[i];
                curr = 0;
            }
        }

        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};