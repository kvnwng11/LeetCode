class Solution {
private:
    vector<int> dp;
    vector<int> counts;
    int ans = 0;

    void solve(int i, vector<int>& nums) {
        if (dp[i] != 0)
            return;

        dp[i] = 1;
        counts[i] = 1;

        for (int j=0; j<i; ++j) {
            if (nums[j] < nums[i]) {
                solve(j, nums);
                if (dp[j] + 1 > dp[i]) {
                    counts[i] = 0;
                    dp[i] = dp[j] + 1;
                }
                if (dp[j] + 1 == dp[i]) {
                    counts[i] += counts[j];
                }
            }
        }
    }  

public:
    int findNumberOfLIS(vector<int>& nums) {
        dp.resize(nums.size(), 0);
        counts.resize(nums.size(), 0);

        for (int i=0; i<nums.size(); ++i){
            solve(i, nums);
            ans = max(ans, dp[i]);
        }

        int res = 0;
        for (int i=0; i<counts.size(); ++i) {
            if (dp[i] == ans)
                res += counts[i];
        }
        return res;
    }
};