class Solution {
private:
    unordered_map<string, multiset<string>> adjList;
    vector<string> itinerary;

    void dfs(string airport) {
        while (adjList[airport].size()) {
            string next = *adjList[airport].begin();
            adjList[airport].erase(adjList[airport].begin());
            dfs(next);
        }
        itinerary.push_back(airport);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto &ticket : tickets)
            adjList[ticket[0]].insert(ticket[1]);
        dfs("JFK");
        return vector<string>(itinerary.rbegin(), itinerary.rend());
    }
};