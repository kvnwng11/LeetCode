class MinStack {
private:
    stack<int> minElts;
    stack<int> elts;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (minElts.empty() || minElts.top() >= val) minElts.push(val);
        elts.push(val);
    }
    
    void pop() {
        int toPop = elts.top();
        if (toPop == minElts.top()) minElts.pop();
        elts.pop();
    }
    
    int top() {
        return elts.top();
    }
    
    int getMin() {
        return minElts.top();
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