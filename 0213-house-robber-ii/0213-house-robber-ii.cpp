class Solution {
private:

    int houseRobber(vector<int>& nums, int start, int end) {
        int n = nums.size();
        int robTwo = 0, robOne = 0;

        for (int i=start; i<=end; ++i) {
            int tmp = max(robTwo + nums[i], robOne);
            robTwo = robOne;
            robOne = tmp;
        }
        return robOne;
    }


public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int ans1 = houseRobber(nums, 0, nums.size()-2);
        int ans2 = houseRobber(nums, 1, nums.size()-1);

        return max(ans1, ans2);
    }
};