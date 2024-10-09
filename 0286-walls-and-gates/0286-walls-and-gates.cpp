class Solution {
private:
    int DIRECTIONS[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    bool inBounds(int i, int j, int m, int n) {
        return 0 <= i && i < m && 0 <= j && j < n;
    }

public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();
        queue<array<int, 2>> q;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (rooms[i][j] == 0)
                    q.push({i, j});
            }
        }

        vector<vector<bool>> seen(m, vector<bool>(n, 0));

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto dir : DIRECTIONS) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (inBounds(newRow, newCol, m, n) && rooms[newRow][newCol] == INT_MAX) {
                    rooms[newRow][newCol] = rooms[row][col] + 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }
};