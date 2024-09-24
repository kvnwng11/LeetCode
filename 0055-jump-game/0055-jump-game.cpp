class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        

        int i=n-1;
        while (i > 0) {
            int j = 1;
            while (i-j >= 0 and nums[i-j] < j)
                j++;

            if (i-j < 0) return false;
            i = i-j;
        }

        return true;
    }
};