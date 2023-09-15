class Solution {
private:
    int twoSumClosest(vector<int>& nums, int left, int target) {
        int ans = 0;
        int minDist = INT_MAX;
        int right = nums.size()-1;
        while (left < right) {
            int currSum = nums[left] + nums[right];
            if (abs(currSum - target) < minDist) {
                minDist = abs(currSum - target);
                ans = currSum;
            }

            if (currSum >= target)
                right--;
            else
                left++;
        }

        return ans;
    }
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minDist = INT_MAX, ans = 0;
        for (int i=0; i<nums.size()-2; ++i) {
            // Closest sum of two
            int currSum = nums[i] + twoSumClosest(nums, i+1, target - nums[i]);

            // Check if better
            if (abs(currSum - target) < minDist) {
                minDist = abs(currSum - target);
                ans = currSum;
            }
        }
        return ans;
    }
};