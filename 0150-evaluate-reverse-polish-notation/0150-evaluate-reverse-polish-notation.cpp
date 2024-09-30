class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        unordered_map<string, function<int(int, int)>> operations = {
            {"+", [](int a, int b) { return a + b; }},
            {"-", [](int a, int b) { return a - b; }},
            {"*", [](int a, int b) { return a * b; }},
            {"/", [](int a, int b) { return a / b; }}
        };


        for (string &token : tokens) {
            if (operations.count(token)) {
                int num2 = nums.top(); nums.pop();
                int num1 = nums.top(); nums.pop();
                nums.push(operations[token](num1, num2));
            }
            else {
                nums.push(stoi(token));
            }
        }
        return nums.top();
    }
};