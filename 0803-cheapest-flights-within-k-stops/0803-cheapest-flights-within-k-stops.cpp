class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, double>>> adjList;
        for (auto &flight : flights) {
            int from = flight[0];
            int to = flight[1];
            double price = flight[2];

            adjList[from].push_back({to, price});
        }

        vector<double> prices(n, DBL_MAX);
        prices[src] = 0;

        //[[0,1,1],[0,2,5],[1,2,1],[2,3,1]]

        for (int i=0; i<=k; ++i) {
            vector<double> newPrices(prices);

            for (int node=0; node<n; ++node) {
                if (prices[node] == DBL_MAX)
                    continue;

                for (auto &pp : adjList[node]) {
                    int to = pp.first;
                    double p = pp.second;

                    newPrices[to] = min(newPrices[to], prices[node] + p);
                }
            }

            prices = newPrices;

            /**/
            for (int j=0; j<n; ++j) {
                cout << prices[j] << " ";
            }
            cout << endl;
            /**/
        }


        return prices[dst] == DBL_MAX? -1 : prices[dst];
    }
};