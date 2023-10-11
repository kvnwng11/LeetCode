class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> d;
        unordered_map<int, int> window;

        // First iteration
        for (int i=0; i<k; ++i) {
            while (!d.empty() and d.back() <= nums[i]) {
                d.pop_back();
            }
            d.push_back(nums[i]);
            window[nums[i]] += 1;
        }
        ans.push_back(d.front());

        // Other iterations
        for (int i=k; i<nums.size(); ++i) {
            // Add to queue
            while (!d.empty() and d.back() <= nums[i]) {
                d.pop_back();
            }
            d.push_back(nums[i]);

            // Update window
            window[nums[i]] += 1;
            window[nums[i - k]] -= 1;

            // Remove elements not in window
            while (!d.empty() and window[d.front()] == 0) {
                d.pop_front();
            }

            // Update ans
            ans.push_back(d.front());
        }

        return ans;
    }
};