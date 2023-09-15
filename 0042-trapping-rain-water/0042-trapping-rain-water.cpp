class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2)
            return 0;

        int leftMax = height[0];
        vector<int> rightMax(height.size());
        int ans = 0;

        // Initialize
        rightMax[height.size()-1] = height[height.size()-1];
        for (int i=height.size()-2; i>=0; --i) {
            rightMax[i] = max(height[i], rightMax[i+1]);
        }

        // Search
        for (int i=1; i<height.size()-1; ++i) {
            leftMax = max(height[i], leftMax);
            ans += min(leftMax, rightMax[i]) - height[i];
        }

        return ans;
    }
};