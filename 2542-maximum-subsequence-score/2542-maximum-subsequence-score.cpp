class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> pairs;
        pairs.reserve(n);
        for (int i=0; i<n; ++i) {
            pairs.push_back({nums1[i], nums2[i]});
        }

        auto mySort = [](const pair<int, int> &p1, const pair<int, int> &p2) {
            return p1.second > p2.second;
        };

        sort(pairs.begin(), pairs.end(), mySort);

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long topKSum = 0;
        for (int i=0; i<k; ++i) {
            topKSum += pairs[i].first;
            minHeap.push(pairs[i].first);
        }

        long long ans = topKSum * pairs[k-1].second;

        for (int i=k; i<n; ++i) {
            topKSum += pairs[i].first - minHeap.top();
            minHeap.pop();
            minHeap.push(pairs[i].first);

            ans = max(ans, topKSum * pairs[i].second);
        }
        return ans;
    }
};