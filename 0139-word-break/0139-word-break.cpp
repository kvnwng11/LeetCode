class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int m = s.size();
        int n = wordDict.size();
        vector<bool> dp(m+1);
        dp[0] = true;

        for (int i=1; i<=m; ++i) {
            for (int j=0; j<n; ++j) {
                string &word = wordDict[j];

                int idx = i - word.size();
                int idx2 = 0;
                if (idx < 0) continue;
                if (idx > 0 and !dp[idx]) continue;

                bool nextWord = false;
                while (idx < i) {
                    char c1 = s[idx];
                    char c2 = word[idx2];
                    if (c1 != c2) {
                        nextWord = true;
                        break;
                    }
                    idx++;
                    idx2++;
                }
                        
                if (nextWord) continue;

                dp[i] = true;
            }
        }

        return dp[m];
    }
};