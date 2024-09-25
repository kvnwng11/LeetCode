class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right;
        int ans = 0;
        unordered_map<char, int> counts;
        int maxFrequency = 0;

        for (right = 0; right < s.size(); ++right) {
            char c = s[right];
            counts[c] += 1;

            maxFrequency = max(maxFrequency, counts[c]);

            if ((right - left + 1 - maxFrequency) > k) {
                counts[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};