class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int targetSum = 0;
        for (int i=0; i<nums.size(); ++i) {
            targetSum += nums[i];
        }
        if (targetSum % 2 == 1)
            return 0;

        targetSum /= 2;
        vector<vector<bool>> dp(nums.size()+1, vector<bool>(targetSum+1, 0));
        dp[0][0] = 1;
        for (int i=1; i<=nums.size(); ++i) {
            int curr = nums[i-1];
            for (int j=0; j<=targetSum; ++j) {
                if (j < curr)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] or dp[i-1][j-curr];
            }
        }
        return dp[nums.size()-1][targetSum];
    }
};