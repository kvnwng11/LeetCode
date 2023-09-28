class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cost(n+1, INT_MAX);
        cost[src] = 0;
        for (int i=0; i<=k; ++i) {
            vector<int> temp = cost;

            for (auto f : flights) {
                int curr = f[0], next = f[1], price = f[2];
                if (cost[curr] == INT_MAX)
                    continue;
                temp[next] = min(temp[next], cost[curr] + price);
            }
            
            cost = temp;
        }
        return cost[dst] == INT_MAX? -1 : cost[dst];
    }
};