class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        
        unordered_map<char, int> counts;
        for (char c : s1)
            counts[c] += 1;

        unordered_map<char, int> window;
        int left = 0;
        int formed = 0, required = counts.size();
        for (int right=0; right<s2.size(); ++right) {
            char c = s2[right];

            window[c] += 1;

            if (window[c] == counts[c]) 
                formed++;
            else if (window[c] == counts[c] + 1)
                formed--;

            if (right >= s1.size()) {
                c = s2[left];
                window[c] -= 1;
                if (window[c] == counts[c]) formed++;
                else if (window[c] == counts[c] - 1) formed--;
                left++;
            }

            if (formed == required) return true;
        }

        return false;
    }
};