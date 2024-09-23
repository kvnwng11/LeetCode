class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int m = s.size();
        int n = wordDict.size();
        vector<bool> dp(m+1);
        dp[0] = true;

        for (int i=1; i<=m; ++i) {
            for (string &word : wordDict) {
                int size = word.size();
                
                if (i - size < 0) continue;

                if (dp[i - size]) {
                    if (s.substr(i - size, size) == word) {
                        dp[i] = true;
                        break;
                    }
                }

            }
        }

        return dp[m];
    }
};