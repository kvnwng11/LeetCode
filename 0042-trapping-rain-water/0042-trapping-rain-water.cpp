class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int left = 0, right = n-1;
        int maxLeft = 0, maxRight = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] >= maxLeft? 
                    (maxLeft = height[left])
                    : ans += (maxLeft - height[left]);
                left++;
            }
            else {
                height[right] >= maxRight? 
                    (maxRight = height[right])
                    : ans += (maxRight - height[right]);
                right--;
            }
        }   
        return ans;
    }
};