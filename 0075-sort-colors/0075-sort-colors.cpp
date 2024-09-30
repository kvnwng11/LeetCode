class Solution {
public:
    void sortColors(vector<int>& nums) {
        int counts[3] = {0};

        for (int num : nums) {
            counts[num]++;
        }

        int pos = 0;
        int color = 0;
        while (pos < nums.size()) {
            while (counts[color] == 0) color++;

            nums[pos] = color;
            counts[color]--;
            pos++;
        }
    }
};