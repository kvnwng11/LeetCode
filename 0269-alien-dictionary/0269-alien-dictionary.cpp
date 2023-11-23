class Solution {
private:
    bool isPrefix(string &s1, string &s2) {
        int length = min(s1.size(), s2.size());
        
        for (int i=0; i<length; ++i)
            if (s1[i] != s2[i]) return false;
        
        return true;
    }
    
    string topologicalsort(unordered_map<char, unordered_set<char>> &adjList) {
        unordered_map<char, int> indegree;
        queue<char> q;
        
        for (auto &[node, neighbors] : adjList) {
            for (char neighbor : neighbors)
                indegree[neighbor]++;
        }
        
        for (auto &p : adjList) {
            int node = p.first;
            if (indegree[node] == 0)
                q.push(node);
        }
        
        string ans = "";
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            
            ans += curr;
            
            for (char neighbor : adjList[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        return adjList.size() == ans.size()? ans : "";
    }
    
public:
    string alienOrder(vector<string>& words) {
        // () Initiailize Adjacency List
        unordered_map<char, unordered_set<char>> adjList;
        for (string &word : words) {
            for (char c : word)
                adjList[c] = unordered_set<char>();
        }
        
        // () Fill adjacency list
        for (int i=0; i<words.size() - 1; ++i) {
            string a = words[i];
            string b = words[i+1];
            
            if (a.size() > b.size() and isPrefix(a, b)) return "";
            
            for (int j=0; j<min(a.size(), b.size()); ++j) {
                if (a[j] != b[j]) {
                    adjList[a[j]].insert(b[j]);
                    break;
                }
            }
        }
        
        // () Topological sort
        string ans = topologicalsort(adjList);
        return ans;
    }
};