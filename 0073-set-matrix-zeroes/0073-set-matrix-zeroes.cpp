class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (matrix[i][j] == 0) {

                    // set col
                    for (int row=0; row<m; ++row)
                        matrix[row][j] = 0;

                    // set row
                    for (int row=0; row<n; ++row)
                        matrix[i][row] = 0;
                }
            }
        }
    }
};