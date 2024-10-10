class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = 0, currGain = 0, totalGain = 0;

        for (int i=0; i<gas.size(); ++i) {
            int gain = gas[i] - cost[i];
            totalGain += gain;
            currGain += gain;

            if (currGain < 0) {
                ans = i+1;
                currGain = 0;
            }
        }

        return totalGain < 0? -1 : ans;
    }
};