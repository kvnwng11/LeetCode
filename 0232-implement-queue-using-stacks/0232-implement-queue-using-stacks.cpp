class MyQueue {
private:
    stack<int> front;
    stack<int> back;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while (!back.empty()) {
            front.push(back.top());
            back.pop();
        }
        front.push(x);
    }
    
    int pop() {
        int ans = peek();
        back.pop();
        return ans;
    }
    
    int peek() {
        int ans = -1;
        while (!front.empty()) {
            back.push(front.top());
            ans = front.top();
            front.pop();
        }
        ans = back.top();
        return ans;
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