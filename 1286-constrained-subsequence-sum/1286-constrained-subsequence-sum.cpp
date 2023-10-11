class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        pq.push({nums[0], 0});
        int ans = nums[0];

        for (int i=1; i<nums.size(); ++i) {
            while (i - k > pq.top().second)
                pq.pop();

            int sum = max(0, pq.top().first) + nums[i];
            pq.push({sum, i});
            ans = max(ans, sum);
        }

        return ans;
    }
};