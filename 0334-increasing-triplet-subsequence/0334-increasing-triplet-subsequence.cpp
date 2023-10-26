class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return 0;

        int j = INT_MAX, k = INT_MAX;
        for (auto n : nums) {
            if (n <= j)
                j = n;
            else if (n <= k)
                k = n;
            else
                return true;
        }

        return false;
    }
};