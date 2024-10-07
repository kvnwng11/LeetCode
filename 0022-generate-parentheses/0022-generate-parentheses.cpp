class Solution {
private:
    vector<string> ans;

    void backtrack(string &curr, int leftCount, int rightCount, int n) {
        if (curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        if (leftCount < n) {
            curr.push_back('(');
            backtrack(curr, leftCount+1, rightCount, n);
            curr.pop_back();
        }

        if (leftCount > rightCount) {
            curr.push_back(')');
            backtrack(curr, leftCount, rightCount+1, n);
            curr.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        string curr = "";
        backtrack(curr, 0, 0, n);
        return ans;
    }
};