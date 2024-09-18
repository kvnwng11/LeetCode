class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int ans = 0;
        int m = maze.size(), n = maze[0].size();
        int add[4][2] = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };

        int startRow = entrance[0];
        int endRow = entrance[1];
        maze[startRow][endRow] = '+';
        
        queue<array<int, 3>> q;
        q.push({startRow, endRow, 0});

        while (!q.empty()) {
            auto [row, col, dist] = q.front();
            q.pop();

            for (int i=0; i<4; ++i) {
                int newRow = row + add[i][0];
                int newCol = col + add[i][1];

                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && maze[newRow][newCol] == '.') {
                    if (newRow == 0 || newRow == m-1 || newCol == 0 || newCol == n-1)  return dist+1;

                    maze[newRow][newCol] = '+';
                    q.push({newRow, newCol, dist+1});
                }
            }
            
            ans++;
        }

        return -1;
    }
};