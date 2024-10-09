class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int downOne = 0;
        int downTwo = 0;
        for (int i=2; i<cost.size()+1; ++i) {
            int minCost = min(downOne + cost[i-1], downTwo + cost[i-2]);
            downTwo = downOne;
            downOne = minCost;
        }
        return downOne;
    }
};