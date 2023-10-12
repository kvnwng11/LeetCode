class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // Create adj list
        unordered_map<int, vector<int>> adjList;
        for (int i=0; i<routes.size(); ++i) {
            for (int stop : routes[i])
                adjList[stop].push_back(i);
        }

        // BFS
        unordered_set<int> seen; // seen stops
        queue<pair<int, int>> q;
        q.push({source, 0});
        while (!q.empty()) {
            auto [curr, numStops] = q.front();
            q.pop();

            //cout << curr << endl;

            // At destination
            if (curr == target) 
                return numStops;


            // Go over buses
            for (int bus : adjList[curr]) {
                if (seen.find(bus) == seen.end()) {

                    // Go over stops
                    for (int nextStop : routes[bus]) {
                        q.push({nextStop, numStops+1});
                    }

                    seen.insert(bus);

                }
            }
        }
        return -1;
    }
};