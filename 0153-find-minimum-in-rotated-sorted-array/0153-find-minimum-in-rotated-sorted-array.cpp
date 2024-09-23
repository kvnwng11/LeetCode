class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            int prev = (mid + n - 1) % n;
            if (nums[mid] < nums[prev]) return nums[mid];
            
            if (nums[mid] < nums[right]) right = mid-1;
            else left = mid+1;
        }

        return nums[left];
    }
};