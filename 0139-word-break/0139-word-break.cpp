struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = new TrieNode();
        for (string& word : wordDict) {
            TrieNode* curr = root;
            for (char c : word) {
                if (!curr->children.count(c))
                    curr->children[c] = new TrieNode();
                curr = curr->children[c];
            }
            curr->isWord = true;
        }


        int m = s.size();
        int n = wordDict.size();
        vector<bool> dp(m);

        for (int i=0; i<m; ++i) {
            if (i == 0 || dp[i-1]) {
                TrieNode* curr = root;
                for (int j=i; j<m; ++j) {
                    char c = s[j];

                    if (!curr->children.count(c))
                        break;
                    
                    curr = curr->children[c];
                    if (curr->isWord)
                        dp[j] = true;
                }
            }
        }

        return dp[m-1];
    }
};