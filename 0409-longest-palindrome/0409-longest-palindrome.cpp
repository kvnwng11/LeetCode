class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> counts;

        int ans = 0;
        int numOnes = 0;
        for (char c : s) {
            counts[c] += 1;

            if (counts[c] == 2) {
                ans += 2;
                numOnes--;
                counts[c] = 0;
            }
            else if (counts[c] == 1) {
                numOnes++;
            }
        }

        return ans + (bool) numOnes;
    }
};