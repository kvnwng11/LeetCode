class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        vector<int> indegree(numCourses);
        for (auto prereq : prerequisites) {
            int to = prereq[0];
            int from = prereq[1];
            indegree[to]++;
            adjList[from].push_back(to);
        }

        queue<int> d;
        for (int i=0; i<numCourses; ++i)
            if (!indegree[i])
                d.push(i);

        int numVisited = 0;
        while (!d.empty()) {
            int curr = d.front();
            d.pop();
            numVisited++;

            for (int neighbor : adjList[curr]) {
                indegree[neighbor]--;
                if (!indegree[neighbor])
                    d.push(neighbor);
            }
        }

        return numVisited == numCourses;
    }
};