class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p1 = 0;
        for (char c : t) {
            if (s[p1] == c)
                p1++;
        }
        return p1 == s.size();
    }
};