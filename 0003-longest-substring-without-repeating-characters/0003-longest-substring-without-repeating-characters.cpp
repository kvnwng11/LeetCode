class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right;
        int ans = 0;
        unordered_map<char, int> charToNextIndex;

        for (right = 0; right<s.size(); ++right) {
            if (charToNextIndex[s[right]] > 0)
                left = max(left, charToNextIndex[s[right]]);

            ans = max(ans, right - left + 1);
            charToNextIndex[s[right]] = right + 1;
        }

        return ans;
    }
};