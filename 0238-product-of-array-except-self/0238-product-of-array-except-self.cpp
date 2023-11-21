class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int fromLeft = 1;
        int fromRight = 1;
        
        for (int i=1; i<n; ++i) {
            fromLeft *= nums[i-1];
            ans[i] = fromLeft;
        }
        
        for (int i=n-2; i>=0; --i) {
            fromRight *= nums[i+1];
            ans[i] *= fromRight;
        }
        
        return ans;
    }
};