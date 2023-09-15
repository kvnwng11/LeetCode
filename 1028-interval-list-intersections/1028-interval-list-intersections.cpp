class Solution {
private:
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;

        int p1 = 0, p2 = 0;
        while (p1 < firstList.size() and p2 < secondList.size()) {
            // if Disjoint
            if (firstList[p1][1] < secondList[p2][0]) {
                p1++;
                continue;
            }
            if (secondList[p2][1] < firstList[p1][0]) {
                p2++;
                continue;
            }

            // Initialize interval
            vector<int> currInterval(2);
            currInterval[0] = max(firstList[p1][0], secondList[p2][0]);
            currInterval[1] = min(firstList[p1][1], secondList[p2][1]);

            // Case 1
            if (firstList[p1][1] < secondList[p2][1]) {
                p1++;
            }
            // Case 2
            else {
                p2++;
            }

            ans.push_back(currInterval);
        }

        return ans;
    }
};