class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int idx = 0;

        for (int start=0; start<s.size(); ++start) {
            if (s[start] != ' ') {
                int end = start;
                while (end < s.size() and s[end] != ' ') s[idx++] = s[end++];
                reverse(s.begin() + idx - (end - start), s.begin() + idx);

                if (idx != 0) s[idx++] = ' ';

                start = end;
            }
        }

        s.erase(s.begin() + idx - 1, s.end());

        return s;
    }
};