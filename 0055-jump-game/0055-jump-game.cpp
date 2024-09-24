class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        

        int i=n-1;
        while (i > 0) {
            bool canJump = false;
            int j = 1;
            while (i-j >= 0) {
                if (nums[i-j] >= j) {
                    i = i-j;
                    canJump = true;
                    break;
                }
                j++;
            }

            if (canJump) continue;
            else return false;
        }

        return true;
    }
};