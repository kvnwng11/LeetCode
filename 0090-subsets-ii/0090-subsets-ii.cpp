class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i=0; i<pow(2, n); ++i) {
            vector<int> curr;
            int num = i;
            int pos = n-1;
            while (num) {
                int rightBit = num & 1;
                if (rightBit) curr.push_back(nums[pos]);
                num >>= 1;
                pos--;
            }
            ans.insert(curr);
        }

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};