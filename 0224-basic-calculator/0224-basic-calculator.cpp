class Solution {
public:
    int calculate(string input) {
        stack<int> s;
        int operand = 0;
        int ans = 0;
        int sign = 1;

        for (int i=0; i<input.size(); ++i) {
            char c = input[i];

            if (isdigit(c)) {
                operand = 10 * operand + (c - '0');
            }
            else if (c == '+') {
                ans += sign * operand;
                sign = 1;
                operand = 0;
            }
            else if (c == '-') {
                ans += sign * operand;
                sign = -1;
                operand = 0;
            }
            else if (c == '(') {
                s.push(ans);
                s.push(sign);
                sign = 1;
                ans = 0;
            }
            else if (c == ')') {
                ans += sign * operand;
                ans *= s.top(); s.pop();
                ans += s.top(); s.pop();
                operand = 0;
            }
            
        }

        return ans + (sign * operand);
    }
};