class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> d;
        vector<int> sum(nums.size());
        int ans = INT_MIN;

        for (int i=0; i<nums.size(); ++i) {
            if (!d.empty() and i - k > d.front()) {
                d.pop_front();
            }

            sum[i] = (!d.empty()? sum[d.front()] : 0) + nums[i];

            while (!d.empty() and sum[d.back()] < sum[i]) {
                d.pop_back();
            }

            if (sum[i] > 0)
                d.push_back(i);

            ans = max(sum[i], ans);
        }

        return ans;
    }
};