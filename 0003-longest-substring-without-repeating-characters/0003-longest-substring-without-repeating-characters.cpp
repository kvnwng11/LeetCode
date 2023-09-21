class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int ans = 0;
        int left = 0;
        for (int right=0; right<s.size(); ++right) {
            if (m.count(s[right]))
                left = max(left, m[s[right]] + 1);

            ans = max(ans, right - left + 1);
            m[s[right]] = right;
        }
        return ans;
    }
};