class SeatManager {
private:
    set<int> unreserved;
public:
    SeatManager(int n) {
        for (int i=1; i<=n; ++i)
            unreserved.insert(i);
    }
    
    int reserve() {
        int ans = *unreserved.begin();
        unreserved.erase(ans);
        return ans;
    }
    
    void unreserve(int seatNumber) {
        unreserved.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */