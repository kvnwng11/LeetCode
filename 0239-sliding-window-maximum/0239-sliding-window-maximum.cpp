class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> d;

        for (int i=0; i<nums.size(); ++i) {
            // Remove leftmost
            if (!d.empty() and d.front() == i-k)
                d.pop_front();

            // Remove anything less than the current number
            while (!d.empty() and nums[i] >= nums[d.back()])
                d.pop_back();
            
            d.push_back(i);

            if (i >= k-1)
                ans.push_back(nums[d.front()]);
        }

        return ans;
    }
};