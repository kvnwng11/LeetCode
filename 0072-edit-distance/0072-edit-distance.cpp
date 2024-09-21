class Solution {
public:
    int minDistance(string word1, string word2) {

        int length1 = word1.size() + 1;
        int length2 = word2.size() + 1;

        vector<vector<int>> dp(length1, vector<int>(length2, 0));

        for (int i=0; i<length1; ++i) {
            dp[i][0] = i;
        }

        for (int j=0; j<length2; ++j) {
            dp[0][j] = j;
        }


        for (int i=1; i<length1; ++i) {
            for (int j=1; j<length2; ++j) {
                char c1 = word1[i-1];
                char c2 = word2[j-1];

                if (c1 == c2) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    int addChar = dp[i][j-1];
                    int deleteChar = dp[i-1][j];
                    int replace = dp[i-1][j-1];
                    dp[i][j] = min(addChar, min(deleteChar, replace)) + 1;
                }
            }
        }

        return dp[word1.size()][word2.size()];
    }
};