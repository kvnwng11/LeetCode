class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1, vector<int>(n+1, 0));

        for (int i=0; i<=n; ++i) {
            dp[1][i] = i;
        }

        for (int i=2; i<=k; ++i) {
            for (int j=1; j<=n; ++j) {
                int ans = INT_MAX;
                int left = 1, right = j;
                while (left <= right) {
                    int mid = left + (right - left) / 2;

                    int lo = dp[i-1][mid-1], hi = dp[i][j-mid];
                    int temp = 1 + max(lo, hi);
                    ans = min(ans, temp);
                    if (lo < hi)
                        left = mid+1;
                    else
                        right = mid-1;
                }
                dp[i][j] = ans;
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
        }

        return dp[k][n];
    }
};