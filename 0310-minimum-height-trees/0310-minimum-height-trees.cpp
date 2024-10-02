class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        if (n < 2) {
            for (int i=0; i<n; ++i) ans.push_back(i);
            return ans;
        }

        unordered_map<int, vector<int>> adjList;
        vector<int> indegree(n, 0);
        for (auto &edge : edges) {
            int a = edge[0], b = edge[1];
            adjList[a].push_back(b);
            adjList[b].push_back(a);
            indegree[a]++;
            indegree[b]++;
        }

        queue<int> leaves;
        for (int i=0; i<n; ++i)
            if (indegree[i]== 1)
                leaves.push(i);
        
        int processed = 0;
        while (n - processed > 2) {
            int size = leaves.size();
            processed += size;

            for (int i=0; i<size; ++i) {
                int curr = leaves.front();
                leaves.pop();

                for (int neighbor : adjList[curr]) {
                    indegree[neighbor]--;
                    if (indegree[neighbor] == 1)
                        leaves.push(neighbor);
                }
            }
        }

        while (!leaves.empty()) {
            ans.push_back(leaves.front());
            leaves.pop();
        }
        return ans;
    }   
};