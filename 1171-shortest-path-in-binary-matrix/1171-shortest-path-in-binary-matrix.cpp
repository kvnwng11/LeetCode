class Solution {
private:
    int add[8][2] = {
        {0, 1},
        {1, 0}, 
        {-1, 0},
        {0, -1},
        {1, 1},
        {-1, 1},
        {1, -1},
        {-1, -1}
    };

    bool inBounds(int x, int y, int n) {
        if (x < 0 or x >= n) return 0;
        if (y < 0 or y >= n) return 0;
        return 1;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        unordered_map<int, unordered_map<int, bool>> visited;
        queue<vector<int>> q;
        if (grid[0][0]) return -1;
        q.push({0, 0, 1});
        while (!q.empty()) {
            int x = q.front()[0];
            int y = q.front()[1];
            int dist = q.front()[2];
            q.pop();
            //cout << x << " " << y << endl;

            if (x == grid.size()-1 and y == grid.size()-1) {
                return dist;
            }
            if (visited[x][y]) continue;

            visited[x][y] = 1;
            for (int i=0; i<8; ++i) {
                int newX = x + add[i][0];
                int newY = y + add[i][1];

                if (inBounds(newX, newY, grid.size()) and grid[newX][newY] == 0 
                        and !visited[newX][newY]) {
                    q.push({newX, newY, dist+1});
                }
            }
        }
        return -1;
    }
};