class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if (prices.size() == 1) return 0;

        int n = prices.size();
        vector<int> holding(n, 0);
        vector<int> notHolding(n, 0);
        notHolding[0] = 0;
        holding[0] = -prices[0];

        for (int i=1; i<prices.size(); ++i) {
            int sellAfterHolding = holding[i-1] + prices[i];
            int buyAfterCooldown = i >= 2? notHolding[i-2] - prices[i] : INT_MIN;

            holding[i] = max(-prices[i], max(buyAfterCooldown, holding[i-1]));
            notHolding[i] = max(0, max(sellAfterHolding, notHolding[i-1]));
        }

        return notHolding[n-1] < 0? 0 : notHolding[n-1];
    }
};