class Solution {
private:
    int ans = 0;

    void dfs(int node, int parent, vector<vector<pair<int, int>>>& adjList) {
        for (auto &[neighbor, sign] : adjList[node]) {
            if (neighbor != parent) {
                ans += sign;
                dfs(neighbor, node, adjList);
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adjList(n);

        for (auto &connection : connections) {
            int from = connection[0];
            int to = connection[1];

            adjList[from].push_back({to, 1});
            adjList[to].push_back({from, 0});
        }

        dfs(0, -1, adjList);
        return ans;
    }
};