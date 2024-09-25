class Solution {
private:
    const int VISITED = INT_MIN;

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int m = matrix.size();
        int n = matrix[0].size();

        int up = 0;
        int down = m-1;
        int left = 0;
        int right = n-1;

        while (ans.size() < m * n) {
            
            // left to right
            for (int col=left; col<=right; ++col)
                ans.push_back(matrix[up][col]);
            
            // go down
            for (int row = up+1; row<=down; ++row)
                ans.push_back(matrix[row][right]);

            // right to left
            if (up != down)
                for (int col=right-1; col>=left; --col)
                    ans.push_back(matrix[down][col]);

            // go up
            if (left != right)
                for (int row=down-1; row > up; --row)
                    ans.push_back(matrix[row][left]);

            left++;
            right--;
            up++;
            down--;
        }

        return ans;
    }
};