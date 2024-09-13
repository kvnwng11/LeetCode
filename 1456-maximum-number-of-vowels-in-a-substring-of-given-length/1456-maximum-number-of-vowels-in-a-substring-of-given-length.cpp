class Solution {
private:
    bool is_vowel(char c) {
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
    }
public:
    int maxVowels(string s, int k) {
        int ans = 0;
        int curr = 0;

        for (int i=0; i<s.size(); ++i) {
            char c = s[i];
            if (is_vowel(c)) curr++;
            if (i >= k and is_vowel(s[i-k])) curr--;
            ans = max(ans, curr);
        }

        return ans;
    }
};