class Solution {
private:
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;

        int p1 = 0, p2 = 0;
        while (p1 < firstList.size() and p2 < secondList.size()) {
            // Initialize interval
            int low = max(firstList[p1][0], secondList[p2][0]);
            int high = min(firstList[p1][1], secondList[p2][1]);

            if (low <= high) {
                vector<int> currInterval(2);
                currInterval[0] = low;
                currInterval[1] = high;
                ans.push_back(currInterval);
            }

            // Case 1
            if (firstList[p1][1] < secondList[p2][1]) 
                p1++;
            // Case 2
            else 
                p2++;
        }

        return ans;
    }
};