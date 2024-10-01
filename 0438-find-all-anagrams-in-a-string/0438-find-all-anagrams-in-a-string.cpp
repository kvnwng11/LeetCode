class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (p.size() > s.size()) return ans;

        unordered_map<char, int> pCounts;
        unordered_map<char, int> windowCounts;

        for (int right = 0; right < p.size(); ++right) {
            pCounts[p[right]] += 1;
        }
        
        int left = 0;
        int formed = 0;
        int required = pCounts.size();
        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];
            windowCounts[c] += 1;

            if (windowCounts[c] == pCounts[c])
                formed++;
            
            if (right >= p.size() - 1) {
                if (formed == required)
                    ans.push_back(left);

                c = s[left];
                if (windowCounts[c] == pCounts[c])
                    formed--;
                windowCounts[c] -= 1;
                left++;
            }
        }
    
        return ans;
    }
};