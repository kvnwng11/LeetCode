class Solution {
private:
    unordered_map<string, unordered_map<string, double>> adjMatrix;

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        ans.reserve(queries.size());

        for (int i=0; i<equations.size(); ++i) {
            string &from = equations[i][0];
            string &to = equations[i][1];

            adjMatrix[from][to] = values[i];
            adjMatrix[to][from] = 1 / values[i];
        }

        for (auto &query : queries) {
            string &src = query[0];
            string &dst = query[1];

            // Not in equations
            if (adjMatrix.find(src) == adjMatrix.end() 
                || adjMatrix.find(dst) == adjMatrix.end()) {
                ans.push_back(-1);
                continue;
            }

            unordered_set<string> visited;
            stack<pair<string, double>> nodes;
            nodes.push({src, 1});

            double res = -1;
            while (!nodes.empty()) {
                auto [curr, value] = nodes.top();
                nodes.pop();

                if (visited.find(curr) != visited.end()) continue;
                visited.insert(curr);

                if (curr == dst) {
                    res = value;
                    break;
                }

                for (auto &[neighbor, divisor] : adjMatrix[curr])
                    nodes.push({neighbor, value * divisor});
            }

            ans.push_back(res);
        }

        return ans;
    }
};