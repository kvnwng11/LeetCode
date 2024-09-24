class Solution {
private:
    int add[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };

    void dfs(vector<vector<int>>& heights, vector<vector<bool>> &visited, int row, int col) {
        visited[row][col] = true;

        for (auto dir : add) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];

            if (newRow < 0 || newRow >= visited.size() || newCol < 0 || newCol >= visited[0].size())
                continue;
            
            if (visited[newRow][newCol])
                continue;
            
            if (heights[newRow][newCol] < heights[row][col])
                continue;

            dfs(heights, visited, newRow, newCol);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacificReachable(m, vector<bool>(n));
        vector<vector<bool>> atlanticReachable(m, vector<bool>(n));

        for (int i=0; i<m; ++i) {
            dfs(heights, pacificReachable, i, 0);
            dfs(heights, atlanticReachable, i, n-1);
        }
        for (int j=0; j<n; ++j) {
            dfs(heights, pacificReachable, 0, j);
            dfs(heights, atlanticReachable, m-1, j);
        }

        vector<vector<int>> ans;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (pacificReachable[i][j] && atlanticReachable[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};