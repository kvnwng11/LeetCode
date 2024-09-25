class Solution {
private:
    int add[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    bool inBounds(int row, int col, int m, int n) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }

    bool dfs(vector<vector<char>>& board, string &word, int pos, int row, int col) {
        if (pos == word.size()-1) return true;

        char orig = board[row][col];
        board[row][col] = '0';
        
        for (auto dir : add) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];

            if (inBounds(newRow, newCol, board.size(), board[0].size()) && board[newRow][newCol] == word[pos+1]) {
                bool res = dfs(board, word, pos+1, newRow, newCol);
                if (res)  {
                    board[row][col] = orig;
                    return true;
                }
            }
        }

        board[row][col] = orig;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[0].size(); ++j) {
                if (board[i][j] == word[0] && dfs(board, word, 0, i, j))
                    return true;
            }
        }

        return false;
    }
};