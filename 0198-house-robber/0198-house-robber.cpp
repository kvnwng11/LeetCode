class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp(n, 0);

        int ans = 0;
        for (int i=0; i<n; ++i) {
            dp[i] = nums[i];
            if (i == 2) dp[i] += dp[i-2];
            else if (i >= 3) dp[i] += max(dp[i-2], dp[i-3]);
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};