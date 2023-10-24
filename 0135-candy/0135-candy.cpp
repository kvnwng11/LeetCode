class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = 0;
        vector<int> candies(n, 1);

        for (int i=1; i<ratings.size(); ++i) {
            if (ratings[i] > ratings[i-1])
                candies[i] = candies[i-1] + 1;
        }

        ans += candies.back();
        for (int i=ratings.size()-2; i>=0; --i) {
            if (ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
            ans += candies[i];
        }

        return ans;
    }
};