class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int N = 0;
        int start = 0;

        while (N < nums.size()) {
            int curr = start;
            int prev = nums[start];

            do {
                int next = (curr + k) % nums.size();
                int tmp = nums[next];
                nums[next] = prev;
                prev = tmp;
                curr = next;
                N++;
            } while(curr != start);

            start++;
        }
    }
};