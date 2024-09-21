class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<int> free(n, 0);
        vector<int> holding(n, 0);

        holding[0] = -prices[0];

        for (int i=1; i<n; ++i) {
            free[i] = max(free[i-1], holding[i-1] + prices[i] - fee);
            holding[i] = max(holding[i-1], free[i-1] - prices[i]);
        }

        return max(holding[n-1], free[n-1]);
    }
};