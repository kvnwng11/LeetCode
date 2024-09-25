struct TrieNode {
    vector<TrieNode*> children;
    bool isWord = false;

    TrieNode() {
        children = vector<TrieNode*>(26, nullptr);
    }
};

class Trie {
private:
    TrieNode* root = new TrieNode();

    bool dfs(string &word, int idx, TrieNode* curr) {
        if (!curr) return false;
        if (idx == word.size()) return curr->isWord;
    
        if (word[idx] == '.') {
            for (int i=0; i<26; ++i) {
                if (dfs(word, idx+1, curr->children[i]))
                    return true;
            }
            return false;
        }
        else
            return dfs(word, idx+1, curr->children[word[idx] - 'a']);
    }

public:
    Trie() = default;

    void add(string &word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children[c - 'a'])
                curr->children[c-'a'] = new TrieNode();
            curr = curr->children[c-'a'];
        }
        curr->isWord = true;
    }

    bool search(string &word) {
        return dfs(word, 0, root);
    }
};

class WordDictionary {
private:
    Trie myTrie;

public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        myTrie.add(word);
    }
    
    bool search(string word) {
        return myTrie.search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */