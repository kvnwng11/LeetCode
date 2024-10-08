class StockSpanner {
private:
    stack<pair<int, int>> s;
public:
    StockSpanner() = default;
    
    int next(int price) {
        int ans = 1;

        while (!s.empty() and s.top().first <= price) {
            ans += s.top().second;
            s.pop();
        }

        s.push({price, ans});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */