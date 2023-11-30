class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int m = word1.size();
        int n = word2.size();
        
        if (m == 0) return n;
        if (n == 0) return m;
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // Initialize
        for (int i=1; i<=m; ++i)
            dp[i][0] = i;
        for (int j=1; j<=n; ++j)
            dp[0][j] = j;
        
        // 2D DP
        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                // Need to make a change to word[j-1]
                if (word1[i-1] != word2[j-1]) {
                    int insertCost = dp[i-1][j] + 1;
                    int deleteCost = dp[i][j-1] + 1;
                    int replaceCost = dp[i-1][j-1] + 1;
                    
                    dp[i][j] = min(insertCost, min(deleteCost, replaceCost));
                }
                // No change
                else {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        
        
        return dp[m][n];
    }
};