class Solution {
private:
    vector<vector<string>> ans;
    vector<string> curr;

    void backtrack(string &s, int start, vector<vector<bool>> &dp) {
        if (start == s.size()) {
            ans.push_back(curr);
            return;
        }

        for (int end = start; end < s.size(); ++end) {
            if (s[start] == s[end] && (end-start <= 2 || dp[start+1][end-1])) {
                dp[start][end] = true;

                curr.push_back(s.substr(start, end - start + 1));
                backtrack(s, end+1, dp);
                curr.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        backtrack(s, 0, dp);
        return ans;
    }
};