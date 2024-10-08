class Solution {
private:
    vector<vector<string>> ans;
    vector<string> curr;

    bool isPalindrome(string &s) {
        int left=0, right = s.size()-1;
        while (left <= right)
            if (s[left++] != s[right--]) return false;
        return true;
    }

    void backtrack(string &s, int idx, string &currString) {
        if (idx == s.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i=idx; i<s.size(); ++i) {
            currString += s[i];
            if (isPalindrome(currString)) {
                curr.push_back(currString);
                string newString = "";
                backtrack(s, i+1, newString);
                curr.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        string curr = "";
        backtrack(s, 0, curr);
        return ans;
    }
};