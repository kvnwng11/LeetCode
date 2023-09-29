class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> adjList;

        for (vector<int> &p : prerequisites) {
            int to = p[0];
            int from = p[1];

            adjList[from].push_back(to);
            indegree[to]++;
        }

        deque<int> d;
        for (int i=0; i<numCourses; ++i) {
            if (indegree[i] == 0)
                d.push_back(i);
        }

        vector<int> ans;
        while (!d.empty()) {
            int node = d.front();
            d.pop_front();

            ans.push_back(node);

            for (int neighbor : adjList[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    d.push_back(neighbor);
            }
        }

        if (ans.size() == numCourses)
            return ans;
        else {
            vector<int> v;
            return v;
        }
    }
};