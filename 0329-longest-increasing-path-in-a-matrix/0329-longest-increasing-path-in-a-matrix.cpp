class Solution {
private:
    int DIRECTIONS[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    vector<vector<int>> maxDist;

    bool inBounds(vector<vector<int>>& matrix, int i, int j) {
        return 0 <= i && i < matrix.size() && 0 <= j && j < matrix[0].size();
    }

    int dfs(vector<vector<int>>& matrix, int row, int col) {
        if (maxDist[row][col] != 0) return maxDist[row][col];
        int ans = 0;

        for (auto dir : DIRECTIONS) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];

            if (inBounds(matrix, newRow, newCol) && matrix[row][col] < matrix[newRow][newCol]) {
                ans = max(ans, dfs(matrix, newRow, newCol));                
            }
        }

        maxDist[row][col] = ans+1;
        return maxDist[row][col];
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        maxDist = vector<vector<int>>(m, vector<int>(n));
        int ans = 0;
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                ans = max(ans, dfs(matrix, i, j));
            }
        }

        return ans;
    }
};