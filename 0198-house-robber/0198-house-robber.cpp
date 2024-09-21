class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int oneAway = nums[n-1];
        int twoAway = 0;

        for (int i=n-2; i>=0; --i) {
            int curr = max(oneAway, twoAway + nums[i]);

            twoAway = oneAway;
            oneAway = curr;
        }

        return oneAway;
    }
};