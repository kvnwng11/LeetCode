class Solution {
private:
    int rob_simple(vector<int>& nums, int start, int end) {
        int t1 = 0;
        int t2 = 0;

        for (int i=start; i<=end; ++i) {
            int temp = t1;
            t1 = max(nums[i] + t2, t1);
            t2 = temp;
        }

        return t1;
    }

public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        int m1 = rob_simple(nums, 0, nums.size()-2);
        int m2 = rob_simple(nums, 1, nums.size()-1);

        return max(m1, m2);
    }
};