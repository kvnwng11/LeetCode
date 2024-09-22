class TrieNode {
private:
    vector<TrieNode*> children;
    char val = '\0';
    bool end = false;

public:
    TrieNode(char _val) : val{_val} {
        children = vector<TrieNode*>(26, nullptr);
    }

    inline void createChild(char c) { children[c - 'a'] = new TrieNode(c); }
    inline bool childExists(char c) { return children[c - 'a']; }
    inline TrieNode* getChild(char c) { return children[c - 'a']; }
    inline void setEnd() { end = true; }
    inline bool isEnd() { return end; }
    inline char getVal() { return val; }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->childExists(c))
                curr->createChild(c);
            curr = curr->getChild(c);
        }
        curr->setEnd();
    }

    TrieNode* searchPrefix(string &prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            curr = curr->getChild(c);
            if (!curr) return nullptr;
        }
        return curr;
    }

    
    void dfs(string &word, vector<string> &res, TrieNode* curr) {
        if (!curr) return;
        if (res.size() == 3) return;
        if (curr->isEnd()) res.push_back(word);
        
        for (int i = 'a'; i<='z'; ++i) {
            if (curr->childExists(i)) {
                word += i;
                dfs(word, res, curr->getChild(i));
                word.pop_back();
            }
        }
        
    }

    vector<string> getProducts(string &query) {
        TrieNode* curr = searchPrefix(query);
        vector<string> ans;
        string word = query;
        dfs(word, ans, curr);
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie myTrie;
        for (string &s : products)
            myTrie.insert(s);
        
        vector<vector<string>> ans;
        string query = "";
        for (char c : searchWord) {
            query += c;
            ans.push_back(myTrie.getProducts(query));
        }
        return ans;
    }
};