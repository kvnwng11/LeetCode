class Solution {
private:
    int dp[50001];
    
    int findMaxProfit(vector<int> &startTime, vector<vector<int>> &jobs) {
        int n = startTime.size();
        
        for (int position = n-1; position >= 0; --position) {
            int currProfit = 0;
            
            int nextIndex = lower_bound(startTime.begin(), startTime.end(), jobs[position][1]) - startTime.begin();
            
            if (nextIndex != n) {
                currProfit = jobs[position][2] + dp[nextIndex];
            }
            else {
                currProfit = jobs[position][2];
            }
            
            if (position == n - 1)
                dp[position] = currProfit;
            else
                dp[position] = max(currProfit, dp[position+1]);
        }
        
        
        return dp[0];
    }
    
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        
        for (int i=0; i<profit.size(); ++i) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        
        for (int i=0; i<profit.size(); ++i) {
            startTime[i] = jobs[i][0];
        }
        
        
        return findMaxProfit(startTime, jobs);
    }
};