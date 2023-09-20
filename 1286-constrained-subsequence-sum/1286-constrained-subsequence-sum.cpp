class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        // [10, 1, 10, 100] k = 2
        deque<pair<int, int>> d;
        d.push_back({nums[0], 0});
        int ans = nums[0];

        for (int i=1; i<nums.size(); ++i) {
            while (!d.empty() and i - d.front().second > k)
                d.pop_front();

            int curr = max(0, d.front().first) + nums[i];
            ans = max(ans, curr);

            while (!d.empty() and d.back().first < curr)
                d.pop_back();
            d.push_back({curr, i});
        }

        return ans;
    }
};