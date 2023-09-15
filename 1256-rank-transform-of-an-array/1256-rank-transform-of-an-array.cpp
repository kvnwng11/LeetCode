class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i=0; i<arr.size(); ++i) {
            pq.push({arr[i], i});
        }

        int rank = 1;
        vector<int> ans(arr.size());
        while (!pq.empty()) {
            auto [val, i] = pq.top();
            pq.pop();

            ans[i] = rank;

            while (!pq.empty() and val == pq.top().first) {
                auto [v, idx] = pq.top();
                pq.pop();

                ans[idx] = rank;
            }


            rank++;
        }

        return ans;
    }
};