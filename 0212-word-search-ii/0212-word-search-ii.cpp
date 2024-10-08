class Solution {
private:
    struct TrieNode {
        vector<TrieNode*> children;
        string word = "";
        bool isWord = false;

        TrieNode() { children = vector<TrieNode*>(26, nullptr); }
    };

    vector<string> ans;
    TrieNode* root = new TrieNode();
    int DIRECTIONS[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    int m;
    int n;

    bool inBounds(int i, int j) {
        return 0 <= i && i < m && 0 <= j && j < n;
    }

    void dfs(vector<vector<char>>& board, int row, int col, TrieNode* curr) {
        if (!curr) return;
        if (curr->word.size() > 0) {
            ans.push_back(curr->word);
            curr->word = "";
        }
        char orig = board[row][col];
        board[row][col] = '.';

        for (auto dir : DIRECTIONS) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];

            if (inBounds(newRow, newCol) && board[newRow][newCol] != '.' 
                        && curr->children[board[newRow][newCol] - 'a']) {
                dfs(board, newRow, newCol, curr->children[board[newRow][newCol] - 'a']);
            }
        }

        board[row][col] = orig;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (string &word : words) {
            TrieNode* curr = root;
            for (char c : word) {
                if (!curr->children[c - 'a'])
                    curr->children[c - 'a'] = new TrieNode();
                curr = curr->children[c - 'a'];
            }
            curr->word = word;
        }

        m = board.size();
        n = board[0].size();
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (root->children[board[i][j] - 'a']) 
                    dfs(board, i, j, root->children[board[i][j] - 'a']);
            }
        }

        return ans;
    }
};