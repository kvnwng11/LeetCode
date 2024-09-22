class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        int hottest = 0;

        for (int i=n-1; i>=0; --i) {
            int currTemp = temperatures[i];
            if (currTemp >= hottest) {
                hottest = currTemp;
                continue;
            }

            int days = 1;
            while (temperatures[i + days] <= currTemp)
                days += ans[i + days];

            ans[i] = days;
        }

        return ans;
    }
};