class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Create Adj List
        unordered_map<int, vector<pair<int, int>>> adjList;
        for (auto &flight : flights) {
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];

            adjList[from].push_back({to, price});
        }

        // Dijkstra's
        vector<int> stops(n+1, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});

        while (!pq.empty()) {
            int dist = pq.top()[0];
            int node = pq.top()[1];
            int numStops = pq.top()[2];
            pq.pop();

            // Already found a better path
            if (numStops > stops[node] or numStops > k + 1) 
                continue;

            // Done
            if (node == dst)
                return dist;

            stops[node] = numStops;
            for (auto &[neighbor, price] : adjList[node]) {
                pq.push({dist + price, neighbor, numStops+1});
            }
            
        }

        return -1;
    }
};