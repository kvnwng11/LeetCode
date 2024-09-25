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
        
        struct Element {
            int index;
            char char_val;
        };
        vector<Element> filteredS;
        for (int i=0; i<s.size(); ++i) {
            char c = s[i];
            if (tCounts.find(c) != tCounts.end())
                filteredS.push_back({i, c});
        }

        int left = 0, right;
        int formed = 0, required = tCounts.size();
        for (right = 0; right < filteredS.size(); ++right) {
            char c = filteredS[right].char_val;
            sCounts[c] += 1;

            if (tCounts.find(c) != tCounts.end() && sCounts[c] == tCounts[c])
                formed++;

            while (left <= right && formed == required) {
                c = filteredS[left].char_val;
                int end = filteredS[right].index;
                int start = filteredS[left].index;
                if (end - start + 1 < minLength) {
                    minLength = end - start + 1;
                    minStart = start;
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