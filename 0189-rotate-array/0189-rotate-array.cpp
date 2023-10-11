class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        int numMoved = 0;
        int i = 0;

        while(numMoved < nums.size()) {
            int curr = i;
            int prev = nums[curr];
            
            do {
                int nextIdx = (curr + k) % nums.size();
                int temp = nums[nextIdx];
                nums[nextIdx] = prev;
                prev = temp;
                curr = nextIdx;

                numMoved++;
            } while (i != curr);

            i++;
        }
    }
};