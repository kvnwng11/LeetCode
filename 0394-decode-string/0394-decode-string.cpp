class Solution {
private:
    bool isNum(string &s) {
        if (s.size() != 1) return false;
        return isdigit(s[0]);
    }
public:
    string decodeString(string str) {
        stack<string> s;

        for (char c : str) {
            if (c == ']') {
                string toRepeat = "";
                while (s.top() != "[") {
                    toRepeat = s.top() + toRepeat;
                    s.pop();
                }
                s.pop();

                int base = 1;
                int num = 0;
                while (!s.empty() && isNum(s.top())) {
                    num += (s.top()[0] - '0') * base;
                    base *= 10;
                    s.pop();
                }
                
                string repeated = "";
                for (int i=0; i<num; ++i) {
                    repeated += toRepeat;
                }
                s.push(repeated);

            }
            else s.push(string{c});
        }

        string ans = "";
        while (!s.empty()) {
            ans = s.top() + ans;
            s.pop();
        }

        return ans;
    }
};