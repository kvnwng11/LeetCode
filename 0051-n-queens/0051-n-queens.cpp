class Solution {
private:
    unordered_map<int, bool> cols;
    unordered_map<int, bool> diags;
    unordered_map<int, bool> antiDiags;

    vector<vector<string>> ans;

    bool canPlace(int row, int col) {
        return !cols[col] && !diags[row - col] && !antiDiags[row + col];
    }

    void place(vector<string> &board, int row, int col) {
        board[row][col] = 'Q';
        cols[col] = true;
        diags[row - col] = true;
        antiDiags[row + col] = true;
    }

    void remove(vector<string> &board, int row, int col) {
        board[row][col] = '.';
        cols[col] = false;
        diags[row - col] = false;
        antiDiags[row + col] = false;
    }

    void solve(vector<string> &board, int row) {
        if (row == board.size()) {
            ans.push_back(board);
            return;
        }

        for (int col=0; col<board.size(); ++col) {
            if (canPlace(row, col)) {

                place(board, row, col);
                
                solve(board, row+1);

                remove(board, row, col);

            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(board, 0);
        return ans;
    }
};