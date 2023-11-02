class LRUCache {
private:
    struct Node {
        int key;
        Node* next = nullptr;
        Node* prev = nullptr;
        Node(int _val) : key{_val} {}
    };

    Node* front = new Node(-1);
    Node* back = new Node(-1);

    unordered_map<int, int> cache;
    unordered_map<int, Node*> place;
    int cap = 0;

    // Place at back
    void addNode(int key) {
        Node* n = new Node(key);

        Node* last = back->prev;
        last->next = n;
        n->prev = last;

        back->prev = n;
        n->next = back;

        place[key] = n;
    }

    // Pop front
    void removeNode() {
        Node* toRemove = front->next;

        front->next = toRemove->next;
        toRemove->next->prev = front;

        int key = toRemove->key;
        cache.erase(key);
        place.erase(key);
        //delete toRemove;
    }

    void updateCache(int key) {
        // Remove from middle
        if (place.count(key)) {
            Node* n = place[key];

            Node* prev = n->prev;
            Node* next = n->next;
            prev->next = next;
            next->prev = prev;
        }

        addNode(key);

        // Too big
        if (cache.size() > cap)
            removeNode();
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        front->next = back;
        back->prev = front;
    }
    
    int get(int key) {
        if (!cache.count(key))
            return -1;

        int ans = cache[key];

        // Update LRU
        updateCache(key);

        return ans;
    }
    
    void put(int key, int value) {
        cache[key] = value;

        // Update LRU
        updateCache(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */