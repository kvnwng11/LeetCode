class Solution {
public:
    bool isMatch(string s, string p) {
        int sizeS = s.size();
        int sizeP = p.size();

        vector<vector<bool>> dp(sizeS+1, vector<bool>(sizeP+1));
        dp[sizeS][sizeP] = true;

        for (int i = sizeS; i >= 0; --i) {
            for (int j = sizeP-1; j >= 0; --j) {
                bool matches = i < sizeS && (s[i] == p[j] || p[j] == '.');

                
                if (j+1 < sizeP && p[j+1] == '*')
                    dp[i][j] = dp[i][j+2] || (matches && dp[i+1][j]);
                else
                    dp[i][j] = matches && dp[i+1][j+1];            
            }
        }

        return dp[0][0];
    }
};