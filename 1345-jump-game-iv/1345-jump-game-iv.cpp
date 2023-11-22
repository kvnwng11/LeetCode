class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> adjList;
        
        for (int i=0; i<arr.size(); ++i) {
            int val = arr[i];
            adjList[val].push_back(i);
        }

        
        vector<bool> visited(n, 0);
        visited[0] = 1;
        
        queue<int> q;
        q.push(0);
        
        int ans = 0;
        
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i=0; i<size; ++i) {
                int curr = q.front();
                q.pop();
                
                //cout << curr << endl;

                if (curr == n-1)
                    return ans;
            
                for (int neighbor : adjList[arr[curr]]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = 1;
                        q.push(neighbor);
                    }
                }

                adjList.erase(arr[curr]);

                if (curr+1 < n and !visited[curr+1]) {
                    visited[curr+1] = 1;
                    q.push(curr+1);
                }
                if (curr-1 >= 0 and !visited[curr-1]) {
                    visited[curr-1] = 1;
                    q.push(curr-1);
                }
            }
            
            ans++;
        
        }
        
        return -1;
    }
};