class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> counts;

        for (int num : nums) {
            if (counts[k-num] > 0) {
                ans++;
                counts[k-num] -= 1;
            }
            else {
                counts[num] += 1;
            }
        }

        return ans;
    }
};