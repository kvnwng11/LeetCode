class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans;
        for (int i=0; i<nums.size(); ++i) {
            int num = nums[i];
            if (m.find(target-num) != m.end()) {
                ans.push_back(i);
                ans.push_back(m[target-num]);
            }
            m[num] = i;
        }
        return ans;
    }  
};