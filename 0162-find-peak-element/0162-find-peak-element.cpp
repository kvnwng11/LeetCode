class Solution {
private:
    bool isPeak(vector<int>& nums, int idx) {
        int n = nums.size();
        bool rGreater = (idx == n-1) || (nums[idx] > nums[idx+1]);
        bool lGreater = (idx == 0) || (nums[idx] > nums[idx-1]);

        return lGreater && rGreater;
    }

public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        
        int left = 0, right = n-1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (isPeak(nums, mid)) {
                return mid;
            }
            else if (mid == 0 || (mid+1 < n && nums[mid] <= nums[mid+1])) {
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }

        return -1;
    }
};