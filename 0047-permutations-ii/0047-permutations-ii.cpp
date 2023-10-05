class Solution {
private:
    vector<vector<int>> ans;

    void getPerm(vector<int> &curr, int idx) {
        if (idx == curr.size()) {
            ans.emplace_back(curr);
            return;
        }

        unordered_set<int> s;
        for (int i = idx; i < curr.size(); ++i) {
            if (s.count(curr[i])) continue;
            s.insert(curr[i]);
            std::swap(curr[i], curr[idx]);
            getPerm(curr, idx+1);
            std::swap(curr[i], curr[idx]);
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        getPerm(nums, 0);
        return ans;
    }
};