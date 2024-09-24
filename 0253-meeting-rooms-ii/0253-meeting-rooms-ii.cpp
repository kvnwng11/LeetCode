class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        priority_queue<int, vector<int>, greater<int>> endTimes;
        endTimes.push(intervals[0][1]);

        for (int i=1; i<intervals.size(); ++i) {
            if (!endTimes.empty() && endTimes.top() <= intervals[i][0]) endTimes.pop();
            endTimes.push(intervals[i][1]);
        }

        return endTimes.size();
    }
};