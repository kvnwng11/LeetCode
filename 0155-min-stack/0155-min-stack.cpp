class MinStack {
private:
    stack<int> s;
    stack<int> small;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);

        if (small.empty() or small.top() >= val)
            small.push(val);
    }
    
    void pop() {
        int top = s.top();
        s.pop();
        if (!small.empty() and small.top() == top)
            small.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return small.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */