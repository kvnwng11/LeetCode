class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2)
            return 0;

        stack<int> s;
        int ans = 0;

        // Search
        for (int i=0; i<height.size(); ++i) {
            while (!s.empty() and height[i] > height[s.top()]) {
                int top = s.top();
                s.pop();

                if (s.empty())
                    break;

                int w = i - s.top() - 1;
                int h = min(height[i], height[s.top()]) - height[top];
                ans += w * h;
            }

            s.push(i);
        }

        return ans;
    }
};