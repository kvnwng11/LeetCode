class Solution {
public:
    bool checkValidString(string s) {
        int left = 0;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '(' or s[i] == '*')
                left++;
            else
                left--;

            if (left < 0) return 0;
        }

        if (left == 0) return 1;

        int right = 0;
        for (int i=s.size()-1; i>=0; --i) {
            if (s[i] == ')' or s[i] == '*')
                right++;
            else
                right--;
            
            if (right < 0) return 0;
        }

        return 1;
    }
};