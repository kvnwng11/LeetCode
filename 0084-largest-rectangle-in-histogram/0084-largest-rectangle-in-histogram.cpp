class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        vector<int> maxLeft(heights.size());
        vector<int> maxRight(heights.size());

        int left = 0;
        maxLeft[0] = -1;
        for (int i=1; i<heights.size(); ++i) {
            left = i-1;
            while (left >= 0 and heights[left] >= heights[i])
                left = maxLeft[left];
            maxLeft[i] = left;
        }

        int right = heights.size()-1;
        maxRight[right] = right+1;
        for (int i=heights.size()-2; i>=0; --i) {
            right = i+1;
            while (right < heights.size() and heights[right] >= heights[i])
                right = maxRight[right];
            maxRight[i] = right;
        }

        int ans = 0;
        for (int i=0; i<heights.size(); ++i) {
            int height = heights[i];
            int length = maxRight[i] - maxLeft[i] - 1;
            ans = max(ans, height * length);
        }

        return ans;
    }
};