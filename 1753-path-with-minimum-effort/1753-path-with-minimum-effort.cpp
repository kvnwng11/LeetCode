class Solution {
private:
    typedef vector<int> vi;
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        int add[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int ans = INT_MAX;
        vector<vector<int>> costs(n, vector<int>(m, INT_MAX));
        priority_queue<vi, vector<vi>, greater<vi>> pq;

        pq.push({0, 0, 0});
        while (!pq.empty()) {
            int dist = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];
            pq.pop();

            if (row == n-1 and col == m-1) return dist;
            if (dist >= costs[row][col]) continue;
            costs[row][col] = dist;

            for (int i=0; i<4; ++i) {
                int newRow = row + add[i][0];
                int newCol = col + add[i][1];

                if (newRow >= 0 and newRow < n and newCol >= 0 and newCol < m) {
                    int newDist = max(dist, abs(heights[row][col] - heights[newRow][newCol]));
                    pq.push({newDist, newRow, newCol});
                }
            }
        }

        return costs[n-1][m-1];
    }
};