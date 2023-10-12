class Solution {
private:
    typedef vector<int> vi;
    int add[4][2] = {
        {0, 1},
        {1, 0},
        {-1, 0},
        {0, -1}
    };
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // Declare variables
        int n = heights.size();
        int m = heights[0].size();

        // Min distance to reach this cell
        vector<vector<int>> costs(n, vector<int>(m, INT_MAX)); 
        costs[0][0] = 0;

        // Dijkstras
        priority_queue<vi, vector<vi>, greater<vi>> pq;
        pq.push({0, 0, 0}); // [dist, row, col]

        while (!pq.empty()) {
            int dist = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];
            pq.pop();

            // Reached dest
            if (row == n-1 and col == m-1)
                return dist;

            // Add neighbors
            for (int i=0; i<4; ++i) {
                int newRow = row + add[i][0];
                int newCol = col + add[i][1];

                if (newRow < 0 or newRow >= n) continue;
                if (newCol < 0 or newCol >= m) continue;

                int newDist = max(dist, abs(heights[row][col] - heights[newRow][newCol]));

                if (newDist < costs[newRow][newCol]) {
                    costs[newRow][newCol] = newDist;
                    pq.push({newDist, newRow, newCol});
                }
            }

        }

        return 0;
    }
};