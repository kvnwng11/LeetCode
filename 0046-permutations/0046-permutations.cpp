class Solution {
private:
    vector<vector<int>> ans;
    vector<int> curr;

    void backtrack(vector<int>& nums) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int num : nums) {
            if (find(curr.begin(), curr.end(), num) == curr.end()) {
                curr.push_back(num);
                backtrack(nums);
                curr.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums);
        return ans;
    }
};