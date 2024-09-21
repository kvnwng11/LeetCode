class Solution {
private:
    map<pair<int, bool>, int> memo;
    int curr = 0;
    int ans = 0;

    int solve(vector<int>& prices, int fee, int idx, bool holding) {
        if (idx == prices.size())
            return 0;
        if (memo.find({idx, holding}) != memo.end()) 
            return memo[{idx, holding}];

        int pick, notpick;

        if (!holding) {
            pick = -prices[idx] + solve(prices, fee, idx+1, false);
            notpick = solve(prices, fee, idx+1, holding);
        }
        else {
            pick = solve(prices, fee, idx+1, holding);
            notpick = prices[idx] + solve(prices, fee, idx+1, true);
        }

        int currProfit = max(pick, notpick);
        memo[{idx, holding}] = currProfit;
        ans = max(currProfit, ans);
        return currProfit;
    }

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