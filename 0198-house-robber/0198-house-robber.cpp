class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int n = nums.size();
        int robTwo = nums[n-1];
        int robOne = max(robTwo, nums[n-2]);

        for (int i=n-3; i>=0; i--) {
            int tmp = max(robOne, robTwo + nums[i]);

            robTwo = robOne;
            robOne = tmp;
        }

        return robOne;
    }
};