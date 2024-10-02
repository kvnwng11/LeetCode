class Solution {
private:
    int DIRECTIONS[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    bool inBounds(int m, int n, int row, int col) {
        return 0 <= row && row < m && 0 <= col && col < n;
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist{mat};

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (dist[i][j] == 0) continue;

                int minNeighbor = m * n;
                if (i > 0) 
                    minNeighbor = min(minNeighbor, dist[i-1][j]);
                if (j > 0)
                    minNeighbor = min(minNeighbor, dist[i][j-1]);
                
                dist[i][j] = minNeighbor + 1;
            }
        }

        for (int i=m-1; i>=0; --i) {
            for (int j=n-1; j>=0; --j) {
                if (dist[i][j] == 0) continue;

                int minNeighbor = m * n;
                if (i < m-1)
                    minNeighbor = min(minNeighbor, dist[i+1][j]);
                if (j < n-1)
                    minNeighbor = min(minNeighbor, dist[i][j+1]);
                
                dist[i][j] = min(dist[i][j], minNeighbor + 1);
            }
        }

        
        
        return dist;
    }
};