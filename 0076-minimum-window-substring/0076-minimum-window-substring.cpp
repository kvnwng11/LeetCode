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

        int formed = 0, required = countT.size();
        for (int right = 0; right < s.size(); ++right) {
            // Add to window
            char c = s[right];
            countS[c] += 1;

            // Check if occurances match up
            if (countT.count(c) and countS[c] == countT[c]) {
                formed++;
            }

            while (left <= right and formed == required) {
                // New answer
                if (right - left + 1 < length) {
                    length = right - left + 1;
                    ansLeft = left;
                }

                c = s[left];
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