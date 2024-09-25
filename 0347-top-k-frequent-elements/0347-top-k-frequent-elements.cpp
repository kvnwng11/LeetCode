class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == nums.size()) return nums;

        // Get character counts
        unordered_map<int, int> counts;
        for (int n : nums)
            counts[n] += 1;

        auto comp = [&counts] (const int n1, const int n2) {
            return counts[n1] > counts[n2];
        };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);

        for (auto &[c, count] : counts) {
            pq.push(c);
            if (pq.size() > k) pq.pop();
        }

        vector<int> ans;
        for (int i=0; i<k; ++i) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};