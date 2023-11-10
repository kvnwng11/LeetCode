class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] < 0) {
                i++;
                continue;
            }

            int n = nums[i] - 1;

            if (0 <= n and n < nums.size() and nums[i] != nums[n])
                swap(nums[i], nums[n]);

            else
                i++;
        }

        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] != i+1)
                return i+1;
        }

        return nums.size()+1;
    }
};