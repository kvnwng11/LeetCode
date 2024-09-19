class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;

        sort(potions.begin(), potions.end());

        for (int i=0; i<spells.size(); ++i) {
            long long target = ceil((double) success / spells[i]);

            if (target > potions.back()) {
                ans.push_back(0);
                continue;
            }

            auto idx = lower_bound(potions.begin(), potions.end(), target) - potions.begin();
        
            ans.push_back(potions.size() - idx);
        }

        return ans;
    }
};