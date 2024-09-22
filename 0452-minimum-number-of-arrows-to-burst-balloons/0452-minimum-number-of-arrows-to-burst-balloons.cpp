class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [] (const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });

        int numRemoved = 0;
        int lastValid = 0;
        for (int i=1; i<points.size(); ++i) {
            if (points[i][0] <= points[lastValid][1])
                numRemoved++;
            else
                lastValid = i;
        }
        return points.size() - numRemoved;
    }
};