class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;

        // 

        while (c > 0 || b > 0 || a > 0) {
            bool rightA = a & 1;
            bool rightB = b & 1;
            bool rightC = c & 1;

            if ((rightA || rightB) != rightC) {
                if (rightC) ans++;
                else ans += rightA + rightB;
            }

            c = c >> 1;
            a = a >> 1;
            b = b >> 1;
        }

        return ans;
    }
};