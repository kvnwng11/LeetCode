class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> characters;
        int ans = 0;

        for (char c : s) {
            if (characters.count(c)) {
                ans += 2;
                characters.erase(c);
            }
            else
                characters.insert(c);
        }

        return ans + !characters.empty();
    }
};