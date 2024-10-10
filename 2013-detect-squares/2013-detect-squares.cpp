class DetectSquares {
private:
    unordered_map<int, unordered_map<int, int>> grid;
    unordered_map<int, vector<int>> points;

public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        grid[x][y] += 1;
        points[x].push_back(y);
    }
    
    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1];
        int x2, x3, x4;
        int y3, y4;

        int ans = 0;
        for (int y2 : points[x1]) {
            if (y2 == y1) continue;

            int width = abs(y2 - y1);

            x3 = x1 - width;
            y3 = y2;
            x4 = x1 - width;
            y4 = y1;
            ans += grid[x3][y3] * grid[x4][y4];

            x3 = x1 + width;
            y3 = y2;
            x4 = x1 + width;
            y4 = y1;
            ans += grid[x3][y3] * grid[x4][y4];
        }

        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */