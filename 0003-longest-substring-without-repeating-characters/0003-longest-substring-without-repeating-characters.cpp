class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int left = 0;
        int ans = 0;
        for (int right=0; right<s.size(); ++right) {
            char curr = s[right];
            
            if (m.find(curr) != m.end()) {
                left = max(m[curr] + 1, left);
            }

            m[curr] = right;
            ans = max(right - left + 1, ans);
        }
        return ans;
    }
};