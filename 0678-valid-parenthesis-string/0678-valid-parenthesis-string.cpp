class Solution {
public:
    bool checkValidString(string s) {
        int openCount = 0;
        int closeCount = 0;
        int n = s.size();

        for (int i=0; i<n; ++i) {
            char c = s[i];

            if (c == '(' || c == '*')
                openCount++;
            else
                openCount--;

            if (s[n - i - 1] == ')' || s[n - i - 1] == '*')
                closeCount++;
            else
                closeCount--;

            if (openCount < 0 || closeCount < 0)
                return false;
        }

        return true;
    }
};