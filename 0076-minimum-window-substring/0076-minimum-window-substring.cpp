class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        if (!t.size() or !s.size()) return "";
        
        int left = 0;
        int ansLeft = 0, length = INT_MAX;

        unordered_map<char, int> countS;
        unordered_map<char, int> countT;

        for (int i=0; i<t.size(); ++i) {
            countT[t[i]] += 1;
        }

        vector<pair<char, int>> filteredS;
        for (int i=0; i<s.size(); ++i) {
            if (countT.count(s[i])) {
                filteredS.push_back({s[i], i});
            }
        }

        int formed = 0, required = countT.size();
        for (int right = 0; right < filteredS.size(); ++right) {
            // Add to window
            char c = filteredS[right].first;
            int idx = filteredS[right].second;
            countS[c] += 1;

            // Check if occurances match up
            if (countT.count(c) and countS[c] == countT[c]) {
                formed++;
            }

            while (left <= right and formed == required) {
                int end = filteredS[right].second;
                int start = filteredS[left].second;

                // New answer
                if (end - start + 1 < length) {
                    length = end - start + 1;
                    ansLeft = start;
                }

                c = filteredS[left].first;
                countS[c] -= 1;

                if (countT.count(c) and countS[c] < countT[c]) {
                    formed--;
                }

                left++;
            }
        }

        return length == INT_MAX? "" : s.substr(ansLeft, length);
    }
};