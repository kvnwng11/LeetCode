class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        int free = 0;
        int holding = -prices[0];

        for (int i=1; i<n; ++i) {
            int oldHolding = holding;

            holding = max(holding, free - prices[i]);
            free = max(free, oldHolding + prices[i] - fee);
        }

        return free;
    }
};