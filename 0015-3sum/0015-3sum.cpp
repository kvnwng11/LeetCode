class Solution {
private:
    void twoSum(vector<int>& nums, vector<vector<int>> &ans, int idx) {
        int left = idx+1, right = nums.size()-1;
        while (left < right) {
            int sum = nums[idx] + nums[left] + nums[right];

            if (sum < 0) left++;
            else if (sum > 0) right--;
            else {
                ans.push_back({nums[idx], nums[left++], nums[right--]});
                while (left < right && nums[left] == nums[left-1]) left++;
            }
        }
    }

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i=0; i<nums.size() && nums[i] <= 0; ++i)
            if (i == 0 || nums[i-1] != nums[i])
                twoSum(nums, ans, i);

        return ans;
    }
};