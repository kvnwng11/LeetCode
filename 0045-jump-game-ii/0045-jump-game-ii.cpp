class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;

        int currEnd = 0, currFar = 0;

        for (int i=0; i<nums.size()-1; ++i) {
            currFar = max(currFar, i + nums[i]);

            if (i == currEnd) {
                ans++;
                currEnd = currFar;
            }
        }

        return ans;
    }
};