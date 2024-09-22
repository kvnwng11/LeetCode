class TrieNode {
private:
    vector<TrieNode*> children;
    bool end = false;

public:
    TrieNode() {
        children = vector<TrieNode*>(26, nullptr);
    }

    void createChild(char c) {
        children[c - 'a'] = new TrieNode();
    }

    bool childExists(char c) {
        return children[c - 'a'];
    }

    TrieNode* getChild(char c) {
        return children[c - 'a'];
    }

    void setNotEnd() { end = false; }

    void setEnd() { end = true; }

    bool isEnd() { return end; }

};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
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
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            curr = curr->getChild(c);
            if (!curr) return false;
        }
        return curr->isEnd();
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            curr = curr->getChild(c);
            if (!curr) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */