class Solution {
private:

    struct myCompare {
        double dist(vector<int> &v) {
            return v[0]*v[0] + v[1]*v[1];
        }
        bool operator() (vector<int> &v1, vector<int> &v2) {
            return dist(v1) > dist(v2);
        }
    };

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, myCompare> pq;
        for (int i=0; i<points.size(); ++i) {
            pq.push(points[i]);
        }
        vector<vector<int>> ans;
        while (k--) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};