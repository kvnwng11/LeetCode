class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        unordered_map<char, char> opposite{
            {'}', '{'},
            {')', '('},
            {']', '['}
        };

        for (char c : s) {
            switch (c) {
                case '(':
                case '{':
                case '[': {
                    brackets.push(c);
                    break;
                }
                case ')': 
                case '}': 
                case ']': {
                    if (brackets.empty() || brackets.top() != opposite[c]) return false;
                    brackets.pop();
                    break;
                }
                default:
                    return false;
            }
        }

        return brackets.empty();
    }
};