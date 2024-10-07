class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0)
            return {""};
        
        vector<string> ans;
        for (int leftCount = 0; leftCount < n; ++leftCount) {
            for (string &leftString : generateParenthesis(leftCount)) {
                for (string &rightString : generateParenthesis(n - 1 - leftCount))
                ans.push_back("(" + leftString + ")" + rightString);
            }
        }

        return ans;
    }
};