class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int currSum = nums[0];
        
        for (int i=1; i<nums.size(); ++i) {
            int num = nums[i];
            
            currSum += num;
            currSum = max(num, currSum);
            ans = max(ans, currSum);
        }
        
        return ans;
    }
};