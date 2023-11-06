class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> unreserved;
    int marker = 1;

public:
    SeatManager(int n) {
    }
    
    int reserve() {
        if (!unreserved.empty()) {
            int res = unreserved.top();
            unreserved.pop();
            return res;
        }

        int ans = marker;
        marker++;
        return ans;
    }
    
    void unreserve(int seatNumber) {
        unreserved.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */