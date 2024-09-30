struct TrieNode {
    vector<TrieNode*> children;
    string word = "";

    TrieNode() : children{vector<TrieNode*>(26)} {}
};


class Solution {
private:
    vector<string> ans;
    int DIRECTIONS[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    TrieNode* root = nullptr;

    bool inBounds(int row, int col, vector<vector<char>>& board) {
        return row >= 0 && row < board.size() && col >= 0 && col < board[0].size();
    }

    void backtrack(TrieNode* parent, vector<vector<char>>& board, int row, int col) {
        char c = board[row][col];
        if (c == '#') return;
        if (!parent->children[c - 'a']) return;

        TrieNode* curr = parent->children[c - 'a'];
        if (!curr->word.empty()) {
            ans.push_back(curr->word);
            curr->word = "";
        }

        board[row][col] = '#';

        for (auto dir : DIRECTIONS) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];

            if (inBounds(newRow, newCol, board)) {
                backtrack(curr, board, newRow, newCol);
            }
        }

        board[row][col] = c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string &word : words) {
            TrieNode* curr = root;
            for (char c : word) {
                if (!curr->children[c - 'a'])
                    curr->children[c - 'a'] = new TrieNode();
                curr = curr->children[c-'a'];
            }
            curr->word = word;
        }


        int m = board.size();
        int n = board[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                char c = board[i][j];
                if (root->children[c - 'a'])
                    backtrack(root, board, i, j);
            }
        }

        return ans;
    }
};