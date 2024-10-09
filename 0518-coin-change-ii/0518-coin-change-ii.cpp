class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned long long> dp(amount+1, 0);
        dp[0] = 1;

        for (int i=n-1; i>=0; --i) {
            int coin = coins[i];
            for (int j=coin; j<=amount; ++j) {
                dp[j] = dp[j] + dp[j-coin];
            }
        }

        return dp[amount];
    }
};