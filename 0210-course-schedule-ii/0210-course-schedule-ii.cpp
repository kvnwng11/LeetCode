class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Create adj list
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses);
        for (auto &p : prerequisites) {
            int from = p[1];
            int to = p[0];

            adjList[from].push_back(to);
            indegree[to]++;
        }

        // Initialize stack
        vector<int> v;
        for (int i=0; i<numCourses; ++i) {
            if (indegree[i] == 0)
                v.push_back(i);
        }

        // Sort
        vector<int> ans;
        while (v.size()) {
            int curr = v.back();
            v.pop_back();

            ans.push_back(curr);

            for (int neighbor : adjList[curr]) {
                indegree[neighbor]--;

                if (indegree[neighbor] == 0)
                    v.push_back(neighbor);
            }
        }

        if (ans.size() == numCourses)
            return ans;
        else
            return {};
    }
};