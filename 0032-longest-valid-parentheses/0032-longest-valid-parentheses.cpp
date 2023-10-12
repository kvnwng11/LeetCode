class Solution {
public:
    int longestValidParentheses(string s) {
        if (!s.size()) return 0;
        int left = 0, right = 0;
        int ans = 0;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '(') {
                left++;
            }
            else {
                right++;
            }

            if (right > left) {
                left = 0;
                right = 0;
            }
            else if (right == left) {
                ans = max(2 * right, ans);
            }
        }
        left = right = 0;
        for (int i=s.size()-1; i>=0; --i) {
            if (s[i] == '(') {
                left++;
            }
            else {
                right++;
            }

            if (right < left) {
                left = 0;
                right = 0;
            }
            else if (right == left) {
                ans = max(2 * right, ans);
            }
        }

        return ans;
    }
};