class Solution {
private:
    // a1 is s, a2 is t
    bool isIncluded(int *a1, int *a2) {
        for (int i=0; i<60; ++i) {
            if (a2[i] > 0 and a1[i] < a2[i])
                return 0;
        }
        return 1;
    }

public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        int length = INT_MAX;
        int start = 0;

        int left = 0;
        int sfreq[60] = {0};
        int tfreq[60] = {0};

        // Initialize
        for (int i=0; i<t.size(); ++i) {
            tfreq[(t[i] - 'A')]++;
        }

        // Sliding window
        for (int right = 0; right < s.size(); ++right) {
            // Grow window until it includes t
            if (find(t.begin(), t.end(), s[right]) != t.end())
                sfreq[(s[right] - 'A')]++;

            // Remove left while window contains t
            while (left <= right and isIncluded(sfreq, tfreq)) {
                // New answer
                if (right - left + 1 < length) {
                    length = right - left + 1;
                    start = left;
                }

                // Remove
                if (find(t.begin(), t.end(), s[right]) != t.end())
                    sfreq[(s[left] - 'A')]--;
                left++;
            }
        }

        return length == INT_MAX? "": s.substr(start, length);
    }
};