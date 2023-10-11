class Solution {
private:

    struct MyComp{
        double dist(vector<int> &v) {
            int x = v[0], y = v[1];
            return x*x + y*y;
        }

        bool operator() (vector<int> &v1, vector<int> &v2) {
            return dist(v1) > dist(v2);
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, MyComp> q;

        for (int i=0; i<points.size(); ++i) {
            q.push(points[i]);
        }

        vector<vector<int>> ans;

        for (int i=0; i<k; ++i) {
            ans.push_back(q.top());
            q.pop();
        }


        return ans;
    }
};