class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int> &b) {
            return a[1] < b[1];
        });

        int ans = 0;
        int lastValid = 0;
        for (int i=1; i<intervals.size(); ++i) {
            if (intervals[i][0] < intervals[lastValid][1]) {
                ans++;
            }
            else {
                lastValid = i;
            }
        }
        return ans;
    }
};