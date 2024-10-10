class Solution {
private:

    unordered_map<int, unordered_map<int, int>> memo;

    int recurse(string &s, string &t, int p1, int p2) {
        if (p2 == t.size()) return 1;
        if (p1 == s.size()) return 0;

        if (memo.count(p1) && memo[p1].count(p2)) return memo[p1][p2];
        
        int ans = recurse(s, t, p1+1, p2);

        if (s[p1] == t[p2]) {
            ans += recurse(s, t, p1+1, p2+1);
        }

        memo[p1][p2] = ans;

        return ans;
    }

public:
    int numDistinct(string s, string t) {
        if (t.size() > s.size()) return 0;

        int m = s.size();
        int n = t.size();

        vector<unsigned long long> dp(n+1);
        dp[n] = 1;

        for (int i=m-1; i>=0; --i) {
            int prev = 1;
            for (int j=n-1; j>=0; --j) {
                int c1 = s[i];
                int c2 = t[j];

                int old = dp[j];

                if (c1 == c2)
                    dp[j] += prev;

                prev = old;
            }
        }

        return dp[0];
    }
};