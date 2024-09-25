class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> checkedRows(m);
        vector<bool> checkedCols(n);

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (matrix[i][j] == 0) {
                    checkedRows[i] = true;
                    checkedCols[j] = true;
                }
            }
        }


        for (int i=0; i<m; ++i)
            if (checkedRows[i])
                for (int j=0; j<n; ++j)
                    matrix[i][j] = 0;

        for (int j=0; j<n; ++j)
            if (checkedCols[j])
                for (int i=0; i<m; ++i)
                    matrix[i][j] = 0;
    }
};