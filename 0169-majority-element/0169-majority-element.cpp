class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int count = 1;


        for (int i=1; i<nums.size(); ++i) {
            int n = nums[i];
            
            if (count == 0)
                ans = n;

            if (ans != n)
                count--;
            else
                count++;
        }

        return ans;
    }
};