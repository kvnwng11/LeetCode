class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);

        // 123
        // 312
        // 213
        // 321

        int a = s.size()-2;
        while (a >= 0 and s[a] >= s[a+1])
            a--;
        if (a < 0) return -1;

        int j = s.size()-1;
        while (j > a and s[j] <= s[a]) {
            j--;
        }

        swap(s[a], s[j]);
        reverse(s.begin()+a+1, s.end());

        return stol(s) <= INT_MAX? stoi(s) : -1;
    }
};