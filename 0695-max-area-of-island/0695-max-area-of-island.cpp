class Solution {
private:
    int DIRECTIONS[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    bool inBounds(vector<vector<int>>& grid, int i, int j) {
        return 0 <= i && i < grid.size() && 0 <= j && j < grid[0].size();
    }

    int getSize(vector<vector<int>>& grid, int i, int j) {
        stack<pair<int, int>> s;
        s.push({i, j});
        int size = 0;
        while (!s.empty()) {
            auto [row, col] = s.top();
            s.pop();

            grid[row][col] = 2;
            size++;

            for (auto dir : DIRECTIONS) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (inBounds(grid, newRow, newCol) && grid[newRow][newCol] == 1) {
                    s.push({newRow, newCol});
                    grid[newRow][newCol] = 2;
                }
            }
        }

        return size;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;

        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    ans = max(ans, getSize(grid, i, j));
                }
            }
        }

        return ans;
    }
};