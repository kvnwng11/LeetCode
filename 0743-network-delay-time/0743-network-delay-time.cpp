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
        stack<pair<int, int>> s;
        s.push({k, 0});

        while (!s.empty()) {
            auto [curr, dist] = s.top();
            s.pop();

            if (dist > minDist[curr]) continue;

            minDist[curr] = dist;

            for (auto &[neighbor, weight] : adjList[curr]) {
                if (dist + weight < minDist[neighbor]) {
                    s.push({neighbor, dist + weight});
                    minDist[neighbor] = dist + weight;
                }
            }
        }

        int ans = 0;
        for (int i=1; i<n+1; ++i) {
            if (minDist[i] == INT_MAX) return -1;
            ans = max(ans, minDist[i]);
        }
        return ans;
    }
};