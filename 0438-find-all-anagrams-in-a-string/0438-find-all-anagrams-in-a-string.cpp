class Solution {
private:
    bool equal(int* a1, int* a2) {
        for (int i=0; i<26; ++i) {
            if (a1[i] != a2[i])
                return 0;
        }
        return 1;
    }

public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {};

        vector<int> ans;
        
        int sChar[26] = {0};
        int pChar[26] = {0};

        // Initialize
        for (int i=0; i<p.size(); ++i) {
            pChar[(p[i] - 'a')]++;
            sChar[(s[i] - 'a')]++;
        }
        if (equal(sChar, pChar)) {
                ans.push_back(0);
        }

        // One pass
        int left = 0;
        for (int i=p.size(); i<s.size(); ++i) {
            // Remove from window
            sChar[(s[left] - 'a')]--;
            sChar[(s[i] - 'a')]++;

            // Check if equal
            if (equal(sChar, pChar)) {
                ans.push_back(left+1);
            }
            left++;
        }

        return ans;
    }
};