class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int numFresh = 0;
        queue<array<int, 3>> q;
        int m = grid.size(), n = grid[0].size();
        int add[4][2] = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 2) q.push({i, j, 0});
                else if (grid[i][j] == 1) numFresh++;
            }
        }

        if (numFresh == 0) return 0;

        while (!q.empty()) {
            auto [row, col, time] = q.front();
            q.pop();

            for (int i=0; i<4; ++i) {
                int newRow = row + add[i][0];
                int newCol = col + add[i][1];

                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                    if (grid[newRow][newCol] == 1) {
                        numFresh--;

                        if (numFresh == 0) return time+1;

                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol, time+1});
                    }
                }
            }
        }

        return -1;
    }
};