class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // Keep list of valid nodes for fast lookup
        unordered_set<int> nodes;
        for (int num : nums)
            nodes.insert(num);

        int ans = 0;

        for (int num : nums) {
            if (!nodes.count(num-1)) {
                int currNum = num;
                int currDist = 0;
                while (nodes.count(currNum)) {
                    currNum++;
                    currDist++;
                }

                ans = max(currDist, ans);
            }
        }
        
        return ans;
    }
};