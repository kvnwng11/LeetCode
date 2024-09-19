class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = costs.size();
        int left = 0;
        int right = n-1;

        for (left = 0; left <= right && left < candidates; ++left) {
            pq.push({costs[left], left});
            
            if (right != left)
                pq.push({costs[right], right});

            right--;
        }

        long long ans = 0;
        while (k--) {
            auto [cost, idx] = pq.top();
            pq.pop();

            ans += cost;

            if (left <= right) {
                if (idx < left and left < n) {
                pq.push({costs[left], left});
                left++;
                }
                else if (right >= 0) {
                    pq.push({costs[right], right});
                    right--;
                }
            }
            
        }

        return ans;
    }
};