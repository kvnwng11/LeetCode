class Solution {
public:
    vector<int> partitionLabels(string s) {

        unordered_map<char, int> furthestIndex;
        for (int i=0; i<s.size(); ++i)
            furthestIndex[s[i]] = i;

        vector<int> ans;
        int furthestGood = 0;
        int lastGood = 0;

        for (int i=0; i<s.size(); ++i) {
            furthestGood = max(furthestGood, furthestIndex[s[i]]);

            if (furthestGood == i) {
                ans.push_back(furthestGood - lastGood + 1);
                lastGood = furthestGood + 1;
            }
        }

        return ans;
    }
};