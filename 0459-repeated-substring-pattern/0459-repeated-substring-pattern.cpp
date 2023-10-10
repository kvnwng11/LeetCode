class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int i=1; i<=n/2; ++i) {
            string substring = s.substr(0, i);
            string curr = "";
            while (curr.size() < s.size()) {
                //cout << substring << endl;
                curr += substring;
            }
            //cout << substring << endl;

            if (curr == s) return true;
        }
        return false;
    }
};