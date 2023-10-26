bool MyCompare(vector<int> &v1, vector<int> &v2) {
    return v1[1] < v2[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), MyCompare);

        int end = INT_MIN;
        int ans = 0;
        for (int i=0; i<intervals.size(); ++i) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            if (currStart >= end) {
                end = currEnd;
            }
            else {
                ans++;
            }
        }

        return ans;
    }
};