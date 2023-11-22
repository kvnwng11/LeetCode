class Solution {
private:
    int evaluate(char op, int x, int y) {
        if (op == '+')
            return x;
        else if (op == '-')
            return -x;
        else if (op == '*')
            return x*y;
        return x / y;
    }
    
    int solve(string &s, int &i) {
        stack<int> st;
        int curr = 0;
        char prev = '+';
        
        while (i < s.size()) {
            char c = s[i];
            
            if (c == '(') {
                i++;
                curr = solve(s, i);
            }
            else if (isdigit(c)) {
                curr = 10*curr + (c - '0');
            }
            else {
                if (prev == '+') {
                    st.push(curr);
                }
                else if (prev == '-') {
                    st.push(-curr);
                }
                else if (prev == '*') {
                    int n = st.top() * curr;
                    st.pop();
                    st.push(n);
                }
                else if (prev == '/') {
                    int n = st.top() / curr;
                    st.pop();
                    st.push(n);
                }
                
                if (c == ')')
                    break;
                
                curr = 0;
                prev = c;
            }
            
            i++;
        }
        
        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
    
public:
    int calculate(string s) {
        s += "@";
        int i = 0;
        return solve(s, i);
    }
};