class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int low = INT_MAX, mid = INT_MAX;

        for (int n : nums) {
            if (n <= low) low = n;
            else if (n <= mid) mid = n;
            else return true;
        }

        return false;
    }
};