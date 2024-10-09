class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if (prices.size() == 1) return 0;

        int n = prices.size();
        vector<int> holding(n, 0);
        vector<int> notHolding(n, 0);
        notHolding[0] = 0;
        holding[0] = -prices[0];

        int sold = INT_MIN;
        int held = -prices[0];
        int reset = 0;

        for (int i=1; i<prices.size(); ++i) {
            int newSold = held + prices[i];
            held = max(held, reset - prices[i]);
            reset = max(reset, sold);
            sold = newSold;
        }

        return max(reset, sold);
    }
};