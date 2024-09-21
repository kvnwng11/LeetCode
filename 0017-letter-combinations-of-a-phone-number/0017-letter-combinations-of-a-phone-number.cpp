class Solution {
private:
    unordered_map<char, string> mappings{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    vector<string> ans;
    string curr = "";

    void recurse(string &digits, int idx) {
        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }

        for (char c : mappings[digits[idx]]) {
            curr += c;

            recurse(digits, idx+1);

            curr.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return ans;
        recurse(digits, 0);
        return ans;
    }
};