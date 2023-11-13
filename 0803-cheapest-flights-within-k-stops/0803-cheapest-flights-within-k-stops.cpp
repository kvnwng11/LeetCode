class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        //[[0,1,1],[0,2,5],[1,2,1],[2,3,1]]

        for (int i=0; i<=k; ++i) {
            vector<int> newPrices(prices);

            for (auto &flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int p = flight[2];

                if (prices[from] != INT_MAX) {
                    newPrices[to] = min(newPrices[to], prices[from] + p);
                }
            }

            prices = newPrices;
        }


        return prices[dst] == INT_MAX? -1 : prices[dst];
    }
};