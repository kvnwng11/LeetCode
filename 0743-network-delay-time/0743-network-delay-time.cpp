class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adjList;
        for (auto &time : times) {
            int src = time[0];
            int dst = time[1];
            int weight = time[2];
            adjList[src].push_back({dst, weight});
        }

        vector<int> minDist(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        minDist[k] = 0;

        while (!pq.empty()) {
            auto [dist, curr] = pq.top();
            pq.pop();

            if (dist > minDist[curr]) continue;

            for (auto &[neighbor, weight] : adjList[curr]) {
                if (dist + weight < minDist[neighbor]) {
                    minDist[neighbor] = dist + weight;
                    pq.push({minDist[neighbor], neighbor});
                }
            }
        }

        int ans = 0;
        for (int i=1; i<n+1; ++i)
            ans = max(ans, minDist[i]);
            
        return ans == INT_MAX? -1 : ans;
    }
};