class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, double>> ratios;

        for (int i=0; i<quality.size(); ++i) {
            double ratio = (double) wage[i] / quality[i];
            ratios.push_back({ratio, quality[i]});
        }

        sort(ratios.begin(), ratios.end());

        priority_queue<int> pq;
        int sum = 0;
        double ans = DBL_MAX;
        for (int i=0; i<ratios.size(); ++i) {
            pq.push(ratios[i].second);
            sum += ratios[i].second;

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                ans = min(ans, sum * ratios[i].first);
            }

        }

        return ans;
    }
};