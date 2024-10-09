#pragma GCC optimize("Ofast","inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
static const auto fast = []() {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0; } ();
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());

        int n = queries.size();
        set<pair<int, int>> queryPair;
        for (int i=0; i<n; ++i)
            queryPair.insert({queries[i], i});
        
        vector<int> ans(n, -1);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int i = 0;
        for (auto &[query, idx] : queryPair) {
            while (i < intervals.size() && query >= intervals[i][0]) {
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }

            while (!pq.empty() && query > pq.top().second) {
                pq.pop();
            }

            if (!pq.empty())
                ans[idx] = pq.top().first;
        }

        return ans;
    }
};