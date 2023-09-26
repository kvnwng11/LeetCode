class Solution {
public:
    int longestValidParentheses(string s) {
        if (!s.size()) return 0;
        stack<int> st;
        int ans = 0, trash = -1;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            }
            else {
                if (st.empty()) {
                    trash = i;
                    continue;
                }

                st.pop();

                if (st.empty())
                    ans = max(ans, i - trash);
                else
                    ans = max(ans, i - st.top());
            }
        }

        return ans;
    }
};