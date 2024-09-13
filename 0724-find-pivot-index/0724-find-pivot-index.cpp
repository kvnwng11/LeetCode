class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rightSum = 0;
        for (int num : nums)
            rightSum += num;

        int leftSum = 0;

        for (int pivot = 0; pivot < nums.size(); ++pivot) {
            rightSum -= nums[pivot];
            if (leftSum == rightSum) return pivot;
            leftSum += nums[pivot];
        }

        return -1;
    }
};