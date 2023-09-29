class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        if (nums.size() == k) return nums;
        int maxPop = nums.size() - k;
        for (int i=0; i<nums.size(); ++i) {
            while (maxPop > 0 and ans.size() and ans.back() > nums[i]) {
                ans.pop_back();
                maxPop--;
            }
            
            ans.push_back(nums[i]);
        }

        while (ans.size() > k) {
            ans.pop_back();
        }

        return ans;
    }
};