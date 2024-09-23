class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0];
        int minProduct = nums[0];
        int ans = maxProduct;

        for (int i=1; i<nums.size(); ++i) {
            int num = nums[i];

            int tmpMax = max(num, max(maxProduct * num, minProduct * num));
            minProduct = min(num, min(maxProduct * num, minProduct * num));

            maxProduct = tmpMax;
            ans = max(maxProduct, ans);
        }

        return ans;
    }
};