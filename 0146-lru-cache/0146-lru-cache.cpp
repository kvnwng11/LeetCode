struct CacheNode {
    int val = -1;
    int key = -1;
    CacheNode* next = nullptr;
    CacheNode* prev = nullptr;
    CacheNode(int _key, int _val) : key{_key}, val{_val} {}
};

class LRUCache {
private:
    unordered_map<int, CacheNode*> keyToNode;

    CacheNode* head = new CacheNode(-1, -1);
    CacheNode* tail = new CacheNode(-1, -1);

    int capacity = 0;

    void moveToEnd(CacheNode* node) {
        CacheNode* prevEnd = tail->prev;
        if (prevEnd == node) return;
        
        node->prev->next = node->next;
        node->next->prev = node->prev;

        prevEnd->next = node;
        node->next = tail;
        tail->prev = node;
        node->prev = prevEnd;
    }

public:
    LRUCache(int _capacity) : capacity{_capacity} {
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!keyToNode.count(key)) return -1;
        int ans = keyToNode[key]->val;

        moveToEnd(keyToNode[key]);

        return ans;
    }
    
    void put(int key, int value) {
        //cout << "put: " << key << " " << value << endl;
        if (keyToNode.count(key)) {
            keyToNode[key]->val = value;
            moveToEnd(keyToNode[key]);
            return;
        }

        if (keyToNode.size() == capacity) {
            CacheNode* toRemove = head->next;
            //cout << toRemove->key << " " << toRemove->val << endl;
            int keyToRemove = toRemove->key;
            keyToNode.erase(keyToRemove);
            head->next = toRemove->next;
            toRemove->next->prev = head;
            delete toRemove;
        }

        CacheNode* newNode = new CacheNode(key, value);
        tail->prev->next = newNode;
        newNode->prev = tail->prev;
        newNode->next = tail;
        tail->prev = newNode;
        keyToNode[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */