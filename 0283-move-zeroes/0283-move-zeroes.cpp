class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int front = 0;
        int curr = 0;
        while (curr < nums.size()) {
            if (nums[curr] != 0) {
                swap(nums[front], nums[curr]);
                front++;
            }
            curr++;
        }
    }
};