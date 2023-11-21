class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0;
        int counts[26] = {0};
        int biggest = 0;
        int ans = 0;

        for (int end = 0; end<s.size(); ++end) {
            int currChar = s[end] - 'A';

            counts[currChar] += 1;

            biggest = max(biggest, counts[currChar]);

            if (end - start + 1 - biggest > k) {
                int outgoingChar = s[start] - 'A';

                counts[outgoingChar] -= 1;

                start++;
            }

            ans = end - start + 1;
        }

        return ans;
    }
};