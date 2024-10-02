class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int targetSum = 0;
        for (int num : nums) targetSum += num;

        if (targetSum % 2 == 1) return false;

        targetSum /= 2;

        int n = nums.size();
        vector<bool> dp(targetSum + 1);
        dp[0] = true;
        for (int num : nums)
            for (int j=targetSum; j>=num; --j)
                dp[j] = dp[j] || dp[j - num];

        return dp[targetSum];
    }
};