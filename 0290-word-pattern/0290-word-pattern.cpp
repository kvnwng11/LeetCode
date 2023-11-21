class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mapping1;
        unordered_map<string, char> mapping2;
        
        string curr = "";
        int idx = 0;
        
        for (int i=0; i<s.size(); ++i) {
            char c = s[i];
        
            if (c != ' ')
                curr += c;
            if (c == ' ' or i == s.size()-1) {
                //cout << "here\n";
                if (idx >= pattern.size())
                    return false;
                
                char p = pattern[idx];
                
                if (mapping1.count(p) == 0 and mapping2.count(curr) == 0) {
                    mapping1[p] = curr;
                    mapping2[curr] = p;
                }
                
                if (curr != mapping1[p] or p != mapping2[curr])
                    return false;
                
                if (i != s.size()-1)
                    curr = "";
                
                idx++;
            }
        }
        
        //cout << "Here\n";
        if (curr != mapping1[pattern.back()] or pattern.back() != mapping2[curr])
            return false;
        
        if (idx < pattern.size()-1)
            return false;
        
        return true;
    }
};