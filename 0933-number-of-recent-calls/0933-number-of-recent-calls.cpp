class RecentCounter {
private:
    int WINDOW = 3000;
    deque<int> cache;

public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        cache.push_back(t);
        while (cache.front() + WINDOW < t)
            cache.pop_front();
        return cache.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */