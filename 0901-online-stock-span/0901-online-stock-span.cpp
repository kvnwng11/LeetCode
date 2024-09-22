class StockSpanner {
private:
    vector<int> lastPrices;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;

        for (int i=lastPrices.size()-1; i>=0; --i) {
            if (price >= lastPrices[i]) {
                ans++;
            }
            else {
                break;
            }
        }

        lastPrices.push_back(price);

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */