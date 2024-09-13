class Solution {
public:
    string removeStars(string s) {
        vector<int> nonStar;

        for (int i=0; i<s.size(); ++ i) {
            if (s[i] == '*') nonStar.pop_back();
            else nonStar.push_back(i);
        }

        string ans = "";
        for (int idx : nonStar) ans += s[idx];
        return ans;
    }
};