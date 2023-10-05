class Solution {
private:
    vector<string> ans;

    void solve(int n, string s, int numOpen, int numClosed) {
        if (numClosed == n) {
            ans.push_back(s);
            return;
        }

        if (numOpen < n) {
            solve(n, s + "(", numOpen+1, numClosed);
        }
        
        if (numClosed < numOpen) {
            solve(n, s + ")", numOpen, numClosed + 1);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        string s = "";
        solve(n, s, 0, 0);
        return ans;
    }
};