class Solution {
private:
    int DIRECTIONS[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    bool inBounds(int i, int j, int n) {
        return 0 <= i && i < n && 0 <= j && j < n;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        vector<vector<bool>> seen(n, vector<bool>(n));

        pq.push({grid[0][0], 0, 0});
        seen[0][0] = true;

        while (!pq.empty()) {
            auto [height, row, col] = pq.top();
            pq.pop();

            ans = max(ans, height);

            if (row == n-1 && col == n-1) break;

            for (auto dir : DIRECTIONS) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (inBounds(newRow, newCol, n) && !seen[newRow][newCol]) {
                    pq.push({grid[newRow][newCol], newRow, newCol});
                    seen[newRow][newCol] = true;
                }
            }
        }

        return ans;
    }
};