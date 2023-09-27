class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> s;
        heights.push_back(0);
        for (int i=0; i<heights.size(); ++i) {
            while (!s.empty() and heights[s.top()] > heights[i]) {
                int top = heights[s.top()];
                s.pop();
                int length = s.empty()? -1 : s.top();
                ans = max(ans, top * (i - length - 1));
            }
            s.push(i);
        }

        return ans;
    }
};