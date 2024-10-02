class Solution {
private:

    int findMaxProfit(vector<array<int, 3>> &jobs) {
        int n = jobs.size(), ans = 0;
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;

        for (int i=0; i<n; ++i) {
            auto [start, end, profit] = jobs[i];

            while (!pq.empty() && start >= pq.top()[0]) {
                ans = max(ans, pq.top()[1]);
                pq.pop();
            }

            pq.push({end, profit + ans});
        }

        while (!pq.empty()) {
            ans = max(ans, pq.top()[1]);
            pq.pop();
        }
        
        return ans;
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<array<int, 3>> jobs;
        for (int i=0; i<profit.size(); ++i)
            jobs.push_back({startTime[i], endTime[i], profit[i]});

        sort(jobs.begin(), jobs.end());

        return findMaxProfit(jobs);
    }
};