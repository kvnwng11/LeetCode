class Solution {
private:
    int DIRECTIONS[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    bool inBounds(int i, int j, vector<vector<char>>& board) {
        return 0 <= i && i < board.size() && 0 <= j && j < board[0].size();
    }

    void markUnreachable(vector<vector<char>>& board, int i, int j) {
        board[i][j] = 'Y';
        stack<pair<int, int>> s;
        s.push({i, j});

        while (!s.empty()) {
            auto [row, col] = s.top();
            s.pop();

            for (auto dir : DIRECTIONS) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (inBounds(newRow, newCol, board) && board[newRow][newCol] == 'O') {
                    board[newRow][newCol] = 'Y';
                    s.push({newRow, newCol});
                }
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int i=0; i<m; ++i) {
            if (board[i][0] == 'O') markUnreachable(board, i, 0);
            if (board[i][n-1] == 'O') markUnreachable(board, i, n-1);
        }

        for (int j=0; j<n; ++j) {
            if (board[0][j] == 'O') markUnreachable(board, 0, j);
            if (board[m-1][j] == 'O') markUnreachable(board, m-1, j);
        }

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'Y') board[i][j] = 'O';
            }
        }
    }
};