class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        s.push(-1);
        int ans = 0;

        for (int i=0; i<heights.size(); ++i) {
            while (s.top() != -1 and heights[s.top()] >= heights[i]) {
                int currHeight = heights[s.top()];
                s.pop();
                int currWidth = i - s.top() - 1;
                ans = max(ans, currHeight * currWidth);
            }
            s.push(i);
        }

        while (s.top() != -1) {
            int currHeight = heights[s.top()];
            s.pop();
            int currWidth = heights.size() - s.top() - 1;
            ans = max(ans, currHeight * currWidth);
        }


        return ans;
    }
};