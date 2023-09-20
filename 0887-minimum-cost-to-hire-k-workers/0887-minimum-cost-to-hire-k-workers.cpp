class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        double ans = DBL_MAX;
        vector<pair<double, int>> v;
        for (int i=0; i<quality.size(); ++i) {
            v.push_back({(double) wage[i] / quality[i], quality[i]});
        }
        sort(v.begin(), v.end());
        priority_queue<int> pq;
        double sum = 0;
        for (int i=0; i<quality.size(); ++i) {
            pq.push(v[i].second);
            sum += v[i].second;

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                ans = min(ans, sum * v[i].first);
            }
        }   

        return ans;
    }
};