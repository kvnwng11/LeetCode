class Solution {
private:
    unordered_map<int, int> memo;

    int recurse(vector<int>& nums, int idx) {
        if (idx >= nums.size()) return 0;
        if (memo.find(idx) != memo.end()) return memo[idx];

        memo[idx] = max(recurse(nums, idx+1), recurse(nums, idx+2) + nums[idx]);
        return memo[idx];
    }

public:
    int rob(vector<int>& nums) {
        return recurse(nums, 0);
    }
};