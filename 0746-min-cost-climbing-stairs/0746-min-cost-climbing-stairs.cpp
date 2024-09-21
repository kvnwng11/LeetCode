class Solution {
private:
    unordered_map<int, int> memo;

    int recurse(int idx, vector<int>& cost) {
        if (idx <= 1) return 0;
        if (memo.find(idx) != memo.end()) return memo[idx];

        int twoStep = cost[idx-2] + recurse(idx-2, cost);
        int oneStep = cost[idx-1] + recurse(idx-1, cost);
        int minCost = min(twoStep, oneStep);
        memo[idx] = minCost;
        return minCost;
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        return recurse(cost.size(), cost);
    }
};