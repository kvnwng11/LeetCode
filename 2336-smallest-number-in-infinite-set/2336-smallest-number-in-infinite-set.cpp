class SmallestInfiniteSet {
private:
    priority_queue<int, vector<int>, greater<int>> addedBack;
    unordered_set<int> unique;
    int smallest = 1;

public:
    SmallestInfiniteSet() : smallest{1} {
        
    }
    
    int popSmallest() {
        int ans = 0;
        if (!addedBack.empty()) {
            ans = addedBack.top();
            addedBack.pop();
            unique.erase(ans);
        }
        else {
            ans = smallest;
            smallest++;
        }
        return ans;
    }
    
    void addBack(int num) {
        if (num < smallest and unique.find(num) == unique.end()) {
            addedBack.push(num);
            unique.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */