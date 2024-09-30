class Solution {
private:
    bool isOperation(string &token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;

        for (string &token : tokens) {
            if (isOperation(token)) {
                char op = token[0];
                int num2 = nums.top(); nums.pop();
                int num1 = nums.top(); nums.pop();
                switch(op) {
                    case '+': {
                        nums.push(num1 + num2);
                        break;
                    }
                    case '-': {
                        nums.push(num1 - num2);
                        break;
                    }
                    case '*': {
                        nums.push(num1 * num2);
                        break;
                    }
                    case '/': {
                        nums.push(num1 / num2);
                        break;
                    }
                }
            }
            else {
                nums.push(stoi(token));
            }
        }
        return nums.top();
    }
};