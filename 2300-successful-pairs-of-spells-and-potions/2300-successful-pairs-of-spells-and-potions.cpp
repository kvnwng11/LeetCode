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

            int left = 0, right = potions.size()-1;
            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (potions[mid] >= target)
                    right = mid - 1;
                else 
                    left = mid + 1;
            }
        
            ans.push_back(potions.size() - left);
        }

        return ans;
    }
};