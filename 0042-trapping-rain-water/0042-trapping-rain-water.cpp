class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2)
            return 0;

        vector<int> leftMax(height.size());
        vector<int> rightMax(height.size());
        int ans = 0;

        // Initialize
        leftMax[0] = height[0];
        for (int i=1; i<height.size(); ++i) {
            leftMax[i] = max(height[i], leftMax[i-1]);
        }
        rightMax[height.size()-1] = height[height.size()-1];
        for (int i=height.size()-2; i>=0; --i) {
            rightMax[i] = max(height[i], rightMax[i+1]);
        }

        // Search
        for (int i=1; i<height.size()-1; ++i) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }

        return ans;
    }
};