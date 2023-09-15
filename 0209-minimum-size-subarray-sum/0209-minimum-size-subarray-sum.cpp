class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;

        int left = 0;
        int sum = 0;
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            while (left <= right and sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left++];
            }
        }

        return ans == INT_MAX? 0: ans;
    }
};