class Solution {
    vector<vector<int>> memo;
    vector<int> rightProfits;

    int recurse(int k, int pos, vector<int> &prices) {
        if (k <= 0) return 0;
        if (pos <= 0) return 0;
        if (memo[k][pos] != -1) return memo[k][pos];


        int profit = 0;
        for (int i=0; i<pos; ++i) {
            int one_less = recurse(k-1, i, prices);
            int newProfit = one_less + (prices[pos] - prices[i]);

            profit = max(profit, newProfit);
        }

        int no_purchase = recurse(k, pos-1, prices);

        memo[k][pos] = max(no_purchase, profit);
        return memo[k][pos];
    }


public:
    int maxProfit(int k, vector<int>& prices) {
        
        int length = prices.size();

        memo = vector<vector<int>>(k+1, vector<int>(length, -1));
        rightProfits = vector<int>(length, 0);
        
        int maxRight = prices.back();
        for (int i=length-2; i>=0; --i) {
            maxRight = max(maxRight, prices[i]);
            rightProfits[i] = max(rightProfits[i+1], maxRight - prices[i]);
        }

        int ans = 0;
        vector<vector<int>> dp(k+1, vector<int>(length+1, -1));
        for (int i=0; i<prices.size(); ++i) {
            ans = max(ans, recurse(k, i, prices));
        }        
        return ans;
    }
};