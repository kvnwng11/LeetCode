class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> counts;
        
        for (char c : text)
            counts[c] += 1;

        string balloon = "balloon";
        
        unordered_map<char, int> balloonCounts;
        for (char c : balloon)
            balloonCounts[c] += 1;

        
        int ans = INT_MAX;

        for (auto &p : balloonCounts) {
            char c = p.first;
            int num = p.second;

            if (balloonCounts.count(c))
                ans = min(ans, counts[c] / num);
            else
                return 0;
        }

        return ans;
    }
};