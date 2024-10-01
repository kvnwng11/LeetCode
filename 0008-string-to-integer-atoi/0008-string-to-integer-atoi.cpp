class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while (i < s.size() && s[i] == ' ') i++;

        int sign = 1;
        if (s[i] == '-') sign = -1;
        if (s[i] == '-' || s[i] == '+') i++;

        long ans = 0;
        while (i < s.size() && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');
            if (sign * ans < (long) INT_MIN) return INT_MIN;
            if (sign * ans > (long) INT_MAX) return INT_MAX;
            i++;
        }

        return ans * sign;
    }
};