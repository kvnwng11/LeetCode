class Solution {
public:
    int longestValidParentheses(string s) {
        if (!s.size()) return 0;
        stack<pair<char, int>> st;
        vector<bool> valid(s.size(), 0);

        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '(') {
                st.push({'(', i});
            }
            else if (!st.empty()){
                auto [p, idx] = st.top();
                st.pop();

                if (p == '(') {
                    valid[idx] = 1;
                    valid[i] = 1;
                }
            }
        }

        int ans = 0, curr = 0;
        for (int i=0; i<valid.size(); ++i) {
            if (valid[i]) curr++;
            else {
                ans = max(ans, curr);
                curr = 0;
            }
        }
        ans = max(ans, curr);

        return ans;
    }
};