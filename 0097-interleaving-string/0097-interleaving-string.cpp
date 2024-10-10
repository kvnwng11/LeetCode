class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;

        int m = s1.size();
        int n = s2.size();
        int b = s3.size();

        vector<bool> dp(n+1);

        for (int i=0; i<=m; ++i) {
            for (int j=0; j<=n; ++j) {

                if (i == 0 && j == 0)
                    dp[j] = true;
                else if (i == 0)
                    dp[j] = dp[j-1] && s2[j-1] == s3[i + j - 1];
                else if (j == 0)
                    dp[j] = dp[j] && s1[i-1] == s3[i + j - 1];
                else
                    dp[j] = dp[j-1] && s2[j-1] == s3[i + j - 1] || dp[j] && s1[i-1] == s3[i + j - 1];

            }
        }

        
        return dp[n];
    }
};