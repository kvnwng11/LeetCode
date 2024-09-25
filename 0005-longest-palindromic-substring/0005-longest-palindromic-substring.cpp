class Solution {
private:
    int longestLength = 0;
    int longestStart = 0;

    void longestPalindrome(string &s, int left, int right) {
        int n = s.size();
        while (left-1 >= 0 and right+1 < n and s[left-1] == s[right+1]) {
            left--;
            right++;
        }
        if (right - left + 1 > longestLength) {
            longestLength = right - left + 1;
            longestStart = left;
        }
    }

public:
    string longestPalindrome(string s) {
        
        int left = 0;
        int right = 0;

        int n = s.size();
        for (int i=0; i<n; ++i) {
            // Odd length
            longestPalindrome(s, i, i);

            // Even length
            if (i+1 < n && s[i] == s[i+1])
                longestPalindrome(s, i, i+1);
        }

        return s.substr(longestStart, longestLength);
    }
};