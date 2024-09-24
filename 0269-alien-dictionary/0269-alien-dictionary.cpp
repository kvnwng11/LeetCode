class Solution {
public:
    string alienOrder(vector<string>& words) {
        // Initialize
        unordered_map<char, vector<char>> adjList;
        unordered_set<char> validChars;
        for (string &word : words) {
            for (char c : word) {
                adjList[c] = vector<char>();
                validChars.insert(c);
            }
        }

        // Construct adjacency list
        vector<char> indegree(26);
        for (int i=0; i<words.size()-1; ++i) {
            string word1 = words[i];
            string word2 = words[i+1];

            if (word1.size() > word2.size() && word1.substr(0, word2.size()) == word2)
                return "";

            for (int j=0; j<min(word1.size(), word2.size()); ++j) {
                if (word1[j] != word2[j]) {
                    adjList[word1[j]].push_back(word2[j]);
                    indegree[word2[j] - 'a']++;
                    break;
                }
            }
        }

        // Topological Sort
        string ans = "";
        int numVisited = 0;
        queue<char> q;
        for (char c : validChars) {
            if (indegree[c - 'a'] == 0)
                q.push(c);
        }

        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            numVisited++;
            ans += curr;

            for (char neighbor : adjList[curr]) {
                indegree[neighbor - 'a']--;
                if (!indegree[neighbor - 'a'])
                    q.push(neighbor);
            }
        }

        return numVisited == adjList.size()? ans : "";
    }
};