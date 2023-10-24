class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> leftC(n, 1);
        vector<int> rightC(n, 1);

        for (int i=1; i<ratings.size(); ++i) {
            if (ratings[i] > ratings[i-1])
                leftC[i] = leftC[i-1] + 1;
        }

        for (int i=ratings.size()-2; i>=0; --i) {
            if (ratings[i] > ratings[i+1])
                rightC[i] = rightC[i+1] + 1;
        }

        int ans = 0;
        for (int i=0; i<ratings.size(); ++i) {
            ans += max(leftC[i], rightC[i]);
        }

        return ans;
    }
};