class Solution {
private:
    double slope(int x1, int y1, int x2, int y2) {
        if (x1 == x2) return INT_MAX;

        return (double)(y1 - y2)/(double)(x1 - x2);
    }

public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        if (points.size() == 1) return 1;

        for (int i=0; i<points.size(); ++i) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            unordered_map<double, int> slopes;

            for (int j=i+1; j<points.size(); ++j) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                double s = slope(x1, y1, x2, y2);
                slopes[s] += 1;
                ans = max(slopes[s] + 1, ans);
            }
        }


        return ans;
    }
};