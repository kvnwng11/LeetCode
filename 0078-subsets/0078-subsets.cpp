class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i=0; i<pow(2, n); ++i) {
            int num = i;

            vector<int> curr;
            int pos = n-1;
            while (num > 0) {
                bool rightBit = num & 1;
                if (rightBit) curr.push_back(nums[pos]);
                pos--;
                num >>= 1;
            }

            ans.push_back(curr);
        }
        return ans;
    }
};