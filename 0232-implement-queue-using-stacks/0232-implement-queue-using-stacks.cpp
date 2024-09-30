class MyQueue {
private:
    stack<int> front;
    stack<int> back;
    int frontElt;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if (front.empty()) frontElt = x;
        front.push(x);
    }
    
    int pop() {
        if (back.empty()) {
            while (!front.empty()) {
                back.push(front.top());
                front.pop();
            }
        }
        int ans = back.top();
        back.pop();
        return ans;
    }
    
    int peek() {
        if (!back.empty()) return back.top();
        return frontElt;
    }
    
    bool empty() {
        return front.empty() && back.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */