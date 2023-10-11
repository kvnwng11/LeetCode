class Solution {
public:
    int trap(vector<int>& height) {
        int maxLeft = height[0], maxRight = height.back();
        int left = 0, right = height.size()-1;
        int ans = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                maxLeft = max(height[left], maxLeft);
                ans += maxLeft - height[left];
                left++;
            }
            else {
                maxRight = max(height[right], maxRight);
                ans += maxRight - height[right];
                right--;
            }
        }

        return ans;
    }
};