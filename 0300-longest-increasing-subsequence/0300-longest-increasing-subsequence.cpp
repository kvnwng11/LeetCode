class Solution {
private:
    int binarySearch(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;

        while (left < right) {
            int mid = left + (right - left)/2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        sub.push_back(nums[0]);

        for (int i=1; i<nums.size(); ++i) {
            int num = nums[i];
            if (num > sub.back()) {
                sub.push_back(num);
            }
            else {
                int j = binarySearch(sub, num);
                sub[j] = num;
            }
        }
        return sub.size();
    }
};