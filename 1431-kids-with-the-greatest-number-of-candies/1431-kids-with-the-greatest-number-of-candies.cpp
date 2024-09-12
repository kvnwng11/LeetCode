class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> ans(n, false);
        int biggest = candies[0];
        for (int num : candies)
            biggest = max(biggest, num);

        for (int i=0; i<n; ++i) 
            ans[i] = candies[i] + extraCandies >= biggest;
        
        return ans;
    }
};