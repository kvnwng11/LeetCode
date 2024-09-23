class Solution {
public:
    int climbStairs(int n) {
        int num1 = 0;
        int num2 = 1;
        for (int i=1; i<=n; ++i) {
            int tmp = num1 + num2;
            num1 = num2;
            num2 = tmp;
        }
        return num2;
    }
};