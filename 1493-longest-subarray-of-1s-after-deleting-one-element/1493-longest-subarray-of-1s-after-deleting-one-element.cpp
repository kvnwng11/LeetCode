class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, right = 0;
        int numZeros = 0;

        for (right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) numZeros++;
            if (numZeros > 1) {
                numZeros -= (1 - nums[left]);
                left++;
            }
        }


        return right - left - 1;
    }
};