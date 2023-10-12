class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int currMax = nums[0];
        int currMin = nums[0];
        int ans = currMax;

        for (int i=1; i<nums.size(); ++i) {
            int curr = nums[i];
            int tempMax = max(curr, max(currMax * curr, currMin * curr));
            currMin = min(curr, min(currMax * curr, currMin * curr));
            currMax = tempMax;

            ans = max(ans, currMax);
        }


        return ans;
    }
};