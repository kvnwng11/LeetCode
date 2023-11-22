class Solution {
private:
    struct PathData {
        int length = 0;
        int row = 0;
        int col = 0;
        int k = 0;
    };
    
    int add[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
    
    bool inBounds(int m, int n, int row, int col) {
        if (row < 0 or row >= m) return false;
        if (col < 0 or col >= n) return false;
        return true;
    }
    
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (k >= m + n - 2)
            return m + n - 2;
        
        vector<vector<int>> seen(m, vector<int>(n, -1));
        queue<PathData> q;
        q.push({0, 0, 0, k});
        seen[0][0] = k;
        
        while (!q.empty()) {
            PathData curr = q.front();
            q.pop();
            
            if (curr.row == m-1 and curr.col == n-1)
                return curr.length;
            
            for (int i=0; i<4; ++i) {
                int newRow = curr.row + add[i][0];
                int newCol = curr.col + add[i][1];
                
                // Out of bounds                
                if (!inBounds(m, n, newRow, newCol)) continue;
                
                int new_k = curr.k - grid[newRow][newCol];
                if (new_k < 0) continue;
                
                // This spot has already been checked, so we should save our eliminations for later
                if (seen[newRow][newCol] >= new_k) continue;
                
                
                PathData newPath = {curr.length + 1, newRow, newCol, new_k};

                q.push(newPath);
                seen[newRow][newCol] = new_k;
                
            }
        }
        
        return -1;
    }
};