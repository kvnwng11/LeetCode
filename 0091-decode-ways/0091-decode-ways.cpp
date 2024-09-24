class Solution {
public:
    int numDecodings(string s) {
        unordered_set<string> valid;
        for (int i=1; i<=26; ++i)
            valid.insert(to_string(i));

        int n = s.size();
        vector<int> dp(n+1);
        dp[0] = 1;
        for (int i=1; i<=n; ++i) {
            string curr{s[i-1]};
            if (valid.find(curr) != valid.end())
                dp[i] += dp[i-1];

            if (i >= 2) {
                curr = s.substr(i-2, 2);
                if (valid.find(curr) != valid.end())
                    dp[i] += dp[i-2];
            }
        } 

        return dp.back();
    }
};