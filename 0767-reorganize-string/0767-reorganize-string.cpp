class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> counts;
        char maxChar;
        int count = 0;
        
        for (char c : s) {
            counts[c] += 1;
            
            // impossible
            if (counts[c] > (s.size()+1)/2) return "";
            
            if (counts[c] > count) {
                maxChar = c;
                count = counts[c];
            }
        }
                
        string ans(s.size(), '0');
        int j = 0;
        while (counts[maxChar]--) {
            ans[j] = maxChar;
            j += 2;
        }
                
        for (auto &[c, num] : counts) {
            while (num > 0 and num--) {
                if (j >= s.size()) j = 1;
                                
                ans[j] = c;
                j += 2;
            }
        }
        
        return ans;
    }
};