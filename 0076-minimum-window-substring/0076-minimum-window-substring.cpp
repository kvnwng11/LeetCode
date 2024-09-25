class Solution {
private:
    bool containedInWindow(unordered_map<char, int>& sCounts, unordered_map<char, int>& tCounts) {
        for (auto &[c, count] : tCounts) {
            if (sCounts[c] < count) return false;
        }
        return true;
    }

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
        for (right = 0; right < s.size(); ++right) {
            int c = s[right];
            sCounts[c] += 1;

            while (left <= right && containedInWindow(sCounts, tCounts)) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    minStart = left;
                }

                sCounts[s[left]] -= 1;
                left++;
            }
        }

        return minStart == -1? "" : s.substr(minStart, minLength);
    }
};