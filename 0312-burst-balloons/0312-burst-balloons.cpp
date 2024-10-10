class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> newNums;
        newNums.push_back(1);
        for (int num : nums)
            newNums.push_back(num);
        newNums.push_back(1);

        int n = newNums.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int left = n-2; left >= 1; --left) {
            for (int right = left; right <= n-2; ++right) {
                for (int i=left; i<=right; ++i) {
                    int gain = newNums[left-1] * newNums[i] * newNums[right+1];
                    int remaining = dp[left][i-1] + dp[i+1][right];
                    dp[left][right] = max(dp[left][right], remaining + gain);
                }
            }
        }

        return dp[1][n-2];
    }
};