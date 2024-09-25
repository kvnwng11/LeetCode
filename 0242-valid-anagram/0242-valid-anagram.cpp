class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sCounts;
        unordered_map<char, int> tCounts;

        for (int i=0; i<max(s.size(), t.size()); ++i) {
            if (i < s.size()) sCounts[s[i]] += 1;
            if (i < t.size()) tCounts[t[i]] += 1;
        }

        return sCounts == tCounts;
    }
};