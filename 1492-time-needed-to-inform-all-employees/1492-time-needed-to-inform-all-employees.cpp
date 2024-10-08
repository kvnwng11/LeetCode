class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // Create adj list
        unordered_map<int, vector<int>> adjList;
        for (int i=0; i<manager.size(); ++i) {
            if (manager[i] != -1) {
                int m = manager[i];
                adjList[m].push_back(i);
            }
        }

        // BFS
        queue<pair<int, int>> q;
        q.push(make_pair(headID, 0));
        int ans = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i=0; i<n; ++i) {
                auto [person, time] = q.front();
                q.pop();

                int dur = time + informTime[person];
                ans = max(time, ans);

                for (int sub : adjList[person]) {
                    q.push(make_pair(sub, dur));
                }
            }
        }
        return ans;
    }
};