class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> counts;
        int ans = 0;

        for (char c : s) {
            counts[c] += 1;

            if (counts[c] == 2) {
                ans += 2;
                counts[c] = 0;
            }
        }

        return ans == s.size()? ans : ans+1;
    }
};