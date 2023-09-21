class Solution {
public:
    string smallestSubsequence(string s) {
        string ans = "";
        vector<bool> seen(26, 0);
        unordered_map<char, int> m;
        for (char c : s) m[c] += 1;
        for (int i = 0; i<s.size(); ++i) {
            m[s[i]] -= 1;
            if (!seen[s[i] - 'a']) {
                while (!ans.empty() and ans.back() > s[i] && m[ans.back()]) {
                    seen[ans.back() - 'a'] = 0;
                    ans.pop_back();
                }
                ans.push_back(s[i]);
                seen[s[i] - 'a'] = 1;
            }
        }

        return ans;
    }
};