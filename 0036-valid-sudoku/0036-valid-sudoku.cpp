class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int N = 9;
        int rows[N] = {0};
        int cols[N] = {0};
        int boxes[N] = {0};

        for (int r=0; r<N; ++r) {
            for (int c=0; c<N; ++c) {
                if (board[r][c] == '.') continue;

                int val = board[r][c] - '0';
                int pos = 1 << (val - 1);
                if (rows[r] & pos) return false;
                rows[r] |= pos;

                if (cols[c] & pos) return false;
                cols[c] |= pos;

                int idx = (r / 3) * 3 + c / 3;
                if (boxes[idx] & pos) return false;
                boxes[idx] |= pos;
            }
        }

        return true;
    }
};