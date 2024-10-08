class Solution {
private:
    vector<vector<int>> ans;
    vector<int> curr;

    void backtrack(vector<int>& candidates, int target, int idx) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i=idx; i<candidates.size() && target >= candidates[i]; ++i) {
            if (i == idx || candidates[i] != candidates[i-1]) {
                curr.push_back(candidates[i]);
                backtrack(candidates, target - candidates[i], i+1);
                curr.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return ans;
    }
};