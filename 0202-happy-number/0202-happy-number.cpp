class Solution {
private:
    int sumSquare(int n) {
        int ans = 0;
        while (n) {
            ans += (n % 10) * (n % 10);
            n /= 10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = sumSquare(n);
        
        while (fast != 1 && slow != fast) {
            slow = sumSquare(slow);
            fast = sumSquare(sumSquare(fast));
        }

        return fast == 1;
    }
};