class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        priority_queue<int> pq;
        vector<int> ans;

        for (int i=0; i<nums.size(); ++i) {
            pq.push(nums[i]);
            counts[nums[i]] += 1;

            if (pq.size() >= k) {

                while (counts[pq.top()] == 0)
                    pq.pop();

                ans.push_back(pq.top());

                counts[nums[i-k+1]] -= 1;
            }
        }


        return ans;
    }
};