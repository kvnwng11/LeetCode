class Solution {
private:
    const int VISITED = INT_MIN;
    int DIRECTIONS[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int currDir = 0;
        int changeDir = 0;

        
        int row = 0, col = 0;

        vector<int> ans{matrix[0][0]};

        matrix[0][0] = VISITED;

        while (changeDir < 2) {
            while (0 <= row + DIRECTIONS[currDir][0]
                      && row + DIRECTIONS[currDir][0] < m 
                      && 0 <= col + DIRECTIONS[currDir][1]
                      && col + DIRECTIONS[currDir][1] < n
                      && matrix[row + DIRECTIONS[currDir][0]][col + DIRECTIONS[currDir][1]] != VISITED) {
                changeDir = 0;

                row += DIRECTIONS[currDir][0];
                col += DIRECTIONS[currDir][1];

                ans.push_back(matrix[row][col]);
                matrix[row][col] = VISITED;
            }

            currDir = (currDir + 1) % 4;
            changeDir++;
        }

        return ans;
    }
};