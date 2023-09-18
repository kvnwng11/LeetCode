class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        int length = -1;
        int start = 0;

        int left = 0;
        unordered_map<char, int> dT;
        unordered_map<char, int> dS;

        // Initialize
        for (int i=0; i<t.size(); ++i)
            dT[t[i]] += 1;

        int required = dT.size();
        int formed = 0;

        // Sliding window
        for (int right = 0; right < s.size(); ++right) {
            int c = s[right];

            // Insert if c is in t
            if (dT.find(c) != dT.end()) {
                dS[c] += 1;

                // Check if match
                if (dT[c] == dS[c])
                    formed++;
            }

            // Remove left while window contains t
            while (left <= right and formed == required) {
                // New answer
                if (length == -1 or right - left + 1 < length) {
                    length = right - left + 1;
                    start = left;
                }

                // Remove
                char toRemove = s[left];
                if (dT.find(toRemove) != dT.end()) {
                    dS[toRemove] -= 1;

                    if (dS[toRemove] < dT[toRemove])
                        formed--;
                }

                left++;
            }
        }

        return length == -1? "": s.substr(start, length);
    }
};