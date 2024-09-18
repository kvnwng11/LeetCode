class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int RANGE = 2 * 10e4 + 2;
        vector<int> counts(RANGE, 0);

        for (int num : nums) {
            counts[num + 10e4]++;
        }

        for (int i=counts.size()-1; i>=0; --i) {
            k -= counts[i];

            if (k <= 0) return i - 10e4;
        }

        return -1;
    }
};