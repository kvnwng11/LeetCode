class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long product = 1;
        int left = 0;
        int ans = 0;

        for (int right=0; right<nums.size(); ++right) {
            product *= nums[right];
            while (left <= right and product >= k)
                product /= nums[left++];
            ans += right - left + 1;
        }

        return ans;
    }
};