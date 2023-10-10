class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        for (int i=0; i<nums.size(); ++i) {
            int maxJump = nums[i];

            for (int jump=0; jump<=maxJump & i+jump < nums.size(); ++jump) {
                dp[i+jump] = min(dp[i+jump], dp[i] + 1);
            }

        }

        return dp[nums.size()-1];
    }
};