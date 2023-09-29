struct TrieNode {
    bool isEnd = 0;
    TrieNode* child[26];

    TrieNode() {
        for (int i=0; i<26; ++i) {
            child[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root = new TrieNode();
public:
    Trie() {
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (int i=0; i<word.size(); ++i) {
            int index = word[i] - 'a';
            if (!curr->child[index])
                curr->child[index] = new TrieNode();
            curr = curr->child[index];
        }
        curr->isEnd = 1;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (int i=0; i<word.size(); ++i) {
            int index = word[i] - 'a';
            if (curr->child[index] == nullptr)
                return 0;
            curr = curr->child[index];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (int i=0; i<prefix.size(); ++i) {
            int index = prefix[i] - 'a';
            if (curr->child[index] == nullptr)
                return 0;
            curr = curr->child[index];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */