class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size()-1;

        while (left < right) {
            int width = right - left;
            int rectHeight = min(height[left], height[right]);
            ans = max(ans, width * rectHeight);
            if (height[left] < height[right]) left++;
            else right--;
        }


        return ans;
    }
};