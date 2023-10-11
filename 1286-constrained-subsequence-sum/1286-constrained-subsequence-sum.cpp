class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> d;
        vector<int> dp(nums.size());
        int ans = INT_MIN;

        for (int i=0; i<nums.size(); ++i) {
            if (!d.empty() and i - k > d.front()) {
                d.pop_front();
            }

            dp[i] = (!d.empty()? dp[d.front()] : 0) + nums[i];

            while (!d.empty() and dp[d.back()] < dp[i]) {
                d.pop_back();
            }

            if (dp[i] > 0)
                d.push_back(i);

            ans = max(dp[i], ans);
        }

        return ans;
    }
};