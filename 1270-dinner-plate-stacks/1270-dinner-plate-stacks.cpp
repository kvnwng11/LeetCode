class DinnerPlates {
private:
    vector<stack<int>> plates;
    set<int> notFull;
    set<int> notEmpty;
    int capacity = 0;

public:
    DinnerPlates(int _cap) {
        capacity = _cap;
    }
    
    void push(int val) {
        int pos = plates.size();

        // All plates are full
        if (notFull.empty()) {
            stack<int> s;
            plates.push_back(s);
            notFull.insert(plates.size()-1);
        }
        else {
            pos = *notFull.begin();
        }

        // Add to leftmost stack
        plates[pos].push(val);
        notEmpty.insert(pos);
        
        // Check if stack is full
        if (plates[pos].size() == capacity) {
            notFull.erase(pos);
        }
    }
    
    int pop() {
        // All plates are empty
        if (notEmpty.size() == 0)
            return -1;

        auto idx = *notEmpty.rbegin();
        int ans = plates[idx].top();
        plates[idx].pop();

        notFull.insert(idx);
        
        if (plates[idx].size() == 0) {
            notEmpty.erase(idx);
        }

        return ans;
    }
    
    int popAtStack(int index) {
        if (index >= plates.size() or plates[index].empty())
            return -1;
        int ans = plates[index].top();
        plates[index].pop();
        notFull.insert(index);
        if (plates[index].empty())
            notEmpty.erase(index);
        return ans;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */