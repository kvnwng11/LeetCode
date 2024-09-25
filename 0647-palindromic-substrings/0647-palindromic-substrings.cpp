class Solution {
    int expand(string &s, int left, int right) {
        int n = s.size();
        int ans = 1;

        while (left-1 >= 0 and right+1 < n and s[left-1] == s[right+1]) {
            left--;
            right++;
            ans++;
        }
        
        return ans;
    }
public:
    int countSubstrings(string s) {
        int ans = 0;

        int n = s.size();
        for (int i=0; i<n; ++i) {
            // Odd length
            ans += expand(s, i, i);

            // Even length
            if (i+1 < n && s[i] == s[i+1])
                ans += expand(s, i, i+1);
        }

        return ans;
    }
};