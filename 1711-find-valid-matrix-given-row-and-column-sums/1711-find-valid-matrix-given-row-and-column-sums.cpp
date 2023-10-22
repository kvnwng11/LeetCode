class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<int> currRowSum(n, 0);
        vector<int> currColSum(m, 0);
        vector<vector<int>> ans(n, vector<int>(m, 0));

        for (int i=0; i<n; ++i) {
            int toAdd = rowSum[i];

            for (int j=0; j<m; ++j) {
                //cout << toAdd << endl;
                // Overflow
                if (toAdd + currColSum[j] > colSum[j]) {
                    ans[i][j] = colSum[j] - currColSum[j];
                    toAdd -= (colSum[j] - currColSum[j]);
                    currColSum[j] = colSum[j];
                }
                // Otherwise
                else {
                    ans[i][j] = toAdd;
                    currColSum[j] += toAdd;
                    toAdd = 0;
                }
            }
            //cout << endl;
        }


        return ans;
    }
};