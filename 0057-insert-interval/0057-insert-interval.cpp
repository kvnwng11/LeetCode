class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        // Initialize
        vector<vector<int>> ans;
        int i = 0;
        int n = intervals.size();

        // Front non-overlapping
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        // Overlapping
        while (i < n && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);

        // Back non-overlapping
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};