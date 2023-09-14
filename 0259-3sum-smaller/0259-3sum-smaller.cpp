class Solution {
private:
    int twoSumSmaller(vector<int>& nums, int start, int target) {
        int ans = 0;

        int left = start, right = nums.size()-1;
        while (left < right) {
            if (nums[left] + nums[right] < target) {
                ans += right - left;
                left++;
            }
            else
                right--;
        }

        return ans;
    }
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i=0; i<nums.size()-2; ++i) {
            ans += twoSumSmaller(nums, i+1, target - nums[i]);
        }
        return ans;
    }
};