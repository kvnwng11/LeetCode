class Solution {
private: 
    const int PRIME = 7;

    int myHash(vector<int>& v) {
        long long base = 1;
        int ans = 0;

        for (int n : v) {
            long long tmp = n * base;
            tmp %= INT_MAX;
            ans += tmp;
            base *= PRIME;
            base %= (INT_MAX / PRIME);
        }

        return ans;
    }

public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<int, int> numRows;
        int ans = 0;
        int n = grid.size(), m = grid[0].size();

        for (int i=0; i<n; ++i) {
            numRows[myHash(grid[i])] += 1;
        }

        for (int j=0; j<m; ++j) {
            vector<int> v;
            for (int i=0; i<n; ++i)
                v.push_back(grid[i][j]);
            
            ans += numRows[myHash(v)];
        }

        return ans;
    }
};