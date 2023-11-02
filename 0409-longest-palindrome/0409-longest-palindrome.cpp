class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> counts;
        for (char c : s)
            counts[c] += 1;

        bool foundOdd = false;
        int ans = 0;
        for (auto &p : counts) {
            int count = p.second;

            if (count % 2 == 1) {
                foundOdd = true;
                ans += count-1;
            }
            else
                ans += count;
            
        }

        if (foundOdd)
            ans += 1;

        return ans;
    }
};