class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        if (t == s) return s;

        unordered_map<char, int> tCounts;
        unordered_map<char, int> sCounts;
        for (char c : t)
            tCounts[c] += 1;

        int minLength = INT_MAX;
        int minStart = -1;

        int left = 0, right;
        int formed = 0, required = tCounts.size();
        for (right = 0; right < s.size(); ++right) {
            int c = s[right];
            sCounts[c] += 1;

            if (tCounts.find(c) != tCounts.end() && sCounts[c] == tCounts[c])
                formed++;

            while (left <= right && formed == required) {
                c = s[left];
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    minStart = left;
                }

                sCounts[c] -= 1;
                if (tCounts.find(c) != tCounts.end() && sCounts[c] < tCounts[c])
                    formed--;

                left++;
            }
        }

        return minStart == -1? "" : s.substr(minStart, minLength);
    }
};