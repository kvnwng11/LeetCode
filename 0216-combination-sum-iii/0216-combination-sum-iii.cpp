class Solution {
private:
    vector<int> curr;
    vector<vector<int>> ans;

    void recurse(int k, int sum, int lastUsed, int n) {
        if (sum > n || curr.size() > k) {
            return;
        }
        else if (sum == n && curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        for (int i=lastUsed+1; i<=9; ++i) {
            curr.push_back(i);
            recurse(k, sum + i, i, n);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        recurse(k, 0, 0, n);
        return ans;
    }
};