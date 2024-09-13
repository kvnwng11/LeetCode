class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int numZeros = 0;
        int ans = 0;

        while (left < nums.size() and right < nums.size()) {
            while (right < nums.size() and numZeros < k) {
                if (nums[right] == 0) numZeros++;
                right++;
            }
            while (right < nums.size() and nums[right] == 1) right++;

            //cout << left << " " << right << " " << numZeros << endl;
            
            ans = max(ans, right - left);
            if (nums[left] == 0) numZeros--;
            left++;
        }

        return ans;
    }
};