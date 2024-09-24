class Solution {
private:
    set<vector<int>> res;
    vector<int> curr;

    void solve(vector<int>& candidates, int target, int idx, int currSum) {
        if (idx >= candidates.size()) return;
        if (currSum > target) return;
        if (currSum == target) {
            vector<int> ans(curr);
            sort(ans.begin(), ans.end());
            res.insert(ans);
            return;
        }

        for (int i=idx; i<candidates.size(); ++i) {
            curr.push_back(candidates[i]);
            solve(candidates, target, i, currSum + candidates[i]);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates, target, 0, 0);
        return vector<vector<int>>(res.begin(), res.end());
    }
};