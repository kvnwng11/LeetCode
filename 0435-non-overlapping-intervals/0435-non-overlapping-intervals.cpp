class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0], end = intervals[0][1];
        int ans = 0;
        for (int i=1; i<intervals.size(); ++i) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            int dist = end - start;
            int currDist = currEnd - currStart;

            // remove one
            if (currStart < end) {
                ans++;

                // keep smaller interval
                if (currEnd <= end) {
                    start = currStart;
                    end = currEnd;
                }
            }
            else {
                start = currStart;
                end = currEnd;
            }
            
        }

        return ans;
    }
};