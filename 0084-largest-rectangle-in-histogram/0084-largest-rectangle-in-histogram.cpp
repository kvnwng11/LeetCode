class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 1) return heights[0];

        stack<int> s;
        s.push(-1);
        int ans = 0;
        int n = heights.size();

        for (int i=0; i<n; ++i) {
            int curr = heights[i];
            while (s.top() != -1 && heights[s.top()] >= curr) {
                int height = heights[s.top()];
                s.pop();
                int width = i - s.top() - 1;
                ans = max(ans, width * height);
            }
            s.push(i);
        }


        while (s.top() != -1) {
            int height = heights[s.top()];
            s.pop();
            int width = n - s.top() - 1;
            ans = max(ans, width * height);
        }

        return ans;
    }
};