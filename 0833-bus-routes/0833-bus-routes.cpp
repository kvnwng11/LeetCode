class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> bus_nodes;
        for (int i=0; i<routes.size(); ++i) {
            for (int j : routes[i])
                bus_nodes[j].push_back(i);
        }

        unordered_set<int> seen;
        queue<pair<int, int>> q;
        q.push({source, 0});
        while (!q.empty()) {
            auto [stop, numBuses] = q.front();
            q.pop();

            if (stop == target)
                return numBuses;

            for (int bus_stop : bus_nodes[stop]) {
                if (seen.find(bus_stop) == seen.end()) {
                    for (int node : routes[bus_stop]) {
                        q.push({node, numBuses+1});
                    }
                    seen.insert(bus_stop);
                }
            }
        }
        return -1;
    }   
};